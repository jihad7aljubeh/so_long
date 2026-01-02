/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihad <jihad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 02:34:34 by jihad             #+#    #+#             */
/*   Updated: 2026/01/02 02:40:51 by jihad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			draw_title(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

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

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		ft_putstr_fd("Game exited by user.\n", 1);
		cleanup_game(game);
		exit(0);
	}
	else if (keycode == KEY_W)
		move_up(game);
	else if (keycode == KEY_A)
		move_left(game);
	else if (keycode == KEY_S)
		move_down(game);
	else if (keycode == KEY_D)
		move_right(game);
	return (0);
}

static void	update_position(t_game *game, int new_x, int new_y)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd("\n", 1);
	draw_map(game);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collectibles == 0)
		{
			ft_putstr_fd("Congratulations! You've won the game!\n", 1);
			cleanup_game(game);
			exit(0);
		}
		return ;
	}
	if (game->map[new_y][new_x] == 'C')
	{
		game->collectibles--;
		game->map[new_y][new_x] = '0';
	}
	update_position(game, new_x, new_y);
}
