/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalju-be <jalju-be@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 02:33:55 by jihad             #+#    #+#             */
/*   Updated: 2026/01/04 18:19:11 by jalju-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(char **map)
{
	if (!map || !map[0])
		return (0);
	if (!is_rectangular(map))
		return (0);
	if (empty_line(map))
		return (0);
	if (!len_same(map))
		return (0);
	if (!check_walls(map))
		return (0);
	if (!check_map_chars(map))
		return (0);
	if (!count_elements(map))
		return (0);
	if (!check_map(map))
		return (0);
	return (1);
}

void	init_game(t_game *game)
{
	t_game	tmp;

	game->mlx = NULL;
	game->win = NULL;
	game->moves = 0;
	game->height = map_height(game->map);
	game->width = map_width(game->map);
	tmp = find_player(game->map);
	game->player_x = tmp.player_x;
	game->player_y = tmp.player_y;
	if (game->player_x == -1 || game->player_y == -1)
		exit_it("Error: player not found\n");
	game->collectibles = count_collectibles(game->map);
	game->img_wall = NULL;
	game->img_floor = NULL;
	game->img_player = NULL;
	game->img_exit = NULL;
	game->img_collect = NULL;
	game->eflag = 0;
}

static char	**fill_map(int fd, char **map)
{
	char	*line;
	int		j;

	j = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[j] = line;
		j++;
		line = get_next_line(fd);
	}
	map[j] = NULL;
	return (map);
}

char	**read_map(int ac, char **av)
{
	int		fd;
	char	**map;

	if (!check_av(ac, av))
		exit_it("Error: Invalid arguments.\n");
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit_it("Error\n");
	map = malloc(sizeof(char *) * 1024);
	if (!map)
	{
		close(fd);
		exit_it("Error: Memory allocation failed.\n");
	}
	map = fill_map(fd, map);
	if (!validate_map(map))
	{
		free_map(map);
		close(fd);
		exit_it("Error: Invalid map.\n");
	}
	close(fd);
	return (map);
}

int	main(int ac, char **av)
{
	t_game	game;

	game.map = read_map(ac, av);
	init_game(&game);
	if (init_mlx(&game))
	{
		cleanup_game(&game);
		exit_it("Error: Failed to load textures\n");
	}
	if (load_textures(&game))
	{
		cleanup_game(&game);
		exit_it("Error: Failed to load textures\n");
	}
	draw_map(&game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
