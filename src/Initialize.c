/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalju-be <jalju-be@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 02:34:23 by jihad             #+#    #+#             */
/*   Updated: 2026/01/04 17:28:40 by jalju-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		return (1);
	}
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE, game->height
			* TILE_SIZE, "so_long");
	if (!game->win)
	{
		return (1);
	}
	return (0);
}

int	load_textures(t_game *game)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "texture/wall.xpm",
			&game->img_width, &game->img_height);
	if (!game->img_wall)
		return (1);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "texture/walk.xpm",
			&game->img_width, &game->img_height);
	if (!game->img_floor)
		return (1);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "texture/player.xpm",
			&game->img_width, &game->img_height);
	if (!game->img_player)
		return (1);
	game->img_collect = mlx_xpm_file_to_image(game->mlx,
			"texture/collectable.xpm", &game->img_width, &game->img_height);
	if (!game->img_collect)
		return (1);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "texture/exit.xpm",
			&game->img_width, &game->img_height);
	if (!game->img_exit)
		return (1);
	return (0);
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
