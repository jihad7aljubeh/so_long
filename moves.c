/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalju-be <jalju-be@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 02:36:18 by jihad             #+#    #+#             */
/*   Updated: 2026/01/04 20:37:02 by jalju-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	move_player(game, 0, -1);
}

void	move_down(t_game *game)
{
	move_player(game, 0, 1);
}

void	move_left(t_game *game)
{
	move_player(game, -1, 0);
}

void	move_right(t_game *game)
{
	move_player(game, 1, 0);
}

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
