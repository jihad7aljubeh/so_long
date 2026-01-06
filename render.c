/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalju-be <jalju-be@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 02:34:34 by jihad             #+#    #+#             */
/*   Updated: 2026/01/04 20:36:53 by jalju-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_title(t_game *game, char tile, int x, int y)
{
	void	*img;

	if (tile == '1')
		img = game->img_wall;
	else if (tile == '0')
		img = game->img_floor;
	else if (tile == 'P')
		img = game->img_player;
	else if (tile == 'C')
		img = game->img_collect;
	else if (tile == 'E')
		img = game->img_exit;
	else
		return ;
	mlx_put_image_to_window(game->mlx, game->win, img, x * game->img_width, y
		* game->img_height);
}

static void	update_position(t_game *game, int new_x, int new_y, char title)
{
	game->map[game->player_y][game->player_x] = title;
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd("\n", 1);
	draw_map(game);
}

void	fished_the_game(t_game *game)
{
	ft_putstr_fd("Congratulations! You've won the game!\n", 1);
	cleanup_game(game);
	exit(0);
}

static int	handle_exit(t_game *game, int dx, int dy)
{
	if (game->map[game->player_y + dy][game->player_x + dx] != 'E')
		return (0);
	if (game->collectibles == 0)
		fished_the_game(game);
	else
		game->eflag = 1;
	return (0);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'C')
	{
		game->collectibles--;
		game->map[new_y][new_x] = '0';
	}
	if (game->eflag)
	{
		update_position(game, new_x, new_y, 'E');
		game->eflag = 0;
		return ;
	}
	handle_exit(game, dx, dy);
	update_position(game, new_x, new_y, '0');
}
