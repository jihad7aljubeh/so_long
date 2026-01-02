/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihad <jihad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 02:34:15 by jihad             #+#    #+#             */
/*   Updated: 2026/01/02 04:23:32 by jihad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_dup(char **map)
{
	int		height;
	char	**map_copy;
	int		i;

	i = 0;
	if (!map)
		return (NULL);
	height = map_height(map);
	map_copy = malloc(sizeof(char *) * (height + 1));
	if (!map_copy)
		return (NULL);
	while (i < height)
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			free_map(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[height] = NULL;
	return (map_copy);
}

static void	flood_fill(char **map, int x, int y, int *found)
{
	if (y < 0 || x < 0 || !map[y] || !map[y][x])
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'C')
		found[0]++;
	if (map[y][x] == 'E')
	{
		found[1] = 1;
		map[y][x] = 'F';
		return ;
	}
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, found);
	flood_fill(map, x - 1, y, found);
	flood_fill(map, x, y + 1, found);
	flood_fill(map, x, y - 1, found);
}

/* ================= PATH VALIDATION ================= */

static int	run_flood_fill(char **map, t_game player, int total_c)
{
	char	**map_cpy;
	int		found[2];

	found[0] = 0;
	found[1] = 0;
	map_cpy = map_dup(map);
	if (!map_cpy)
		return (0);
	flood_fill(map_cpy, player.player_x, player.player_y, found);
	free_map(map_cpy);
	if (found[0] != total_c || !found[1])
		return (0);
	return (1);
}

int	check_map(char **map)
{
	t_game	player;
	int		total_c;

	if (!map)
		return (0);
	total_c = count_collectibles(map);
	player = find_player(map);
	if (player.player_x == -1 || player.player_y == -1)
		return (0);
	return (run_flood_fill(map, player, total_c));
}
