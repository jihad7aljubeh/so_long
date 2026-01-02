/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihad <jihad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 02:34:23 by jihad             #+#    #+#             */
/*   Updated: 2026/01/02 16:08:15 by jihad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_it("Error: mlx_init failed\n");
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE, game->height
			* TILE_SIZE, "so_long");
	if (!game->win)
		exit_it("Error: mlx_new_window failed\n");
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
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "texture/ext.xpm",
			&game->img_width, &game->img_height);
	if (!game->img_exit)
		return (1);
	return (0);
}
