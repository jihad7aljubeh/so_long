/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihad <jihad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 02:34:42 by jihad             #+#    #+#             */
/*   Updated: 2026/01/02 16:05:41 by jihad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include <sys/time.h>
# include "gnl/get_next_line.h"
# include "minilibx-linux/mlx.h"

# define KEY_ESC	65307
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define TILE_SIZE	42

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	char	**map_copy;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
	int		img_width;
	int		img_height;
}	t_game;

int		check_map_chars(char **map);
int		is_rectangular(char **map);
int		empty_line(char **map);
int		len_same(char **map);
int		check_walls(char **map);
int		count_elements(char **map);
int		map_height(char **map);
int		map_width(char **map);
int		validate_map(char **map);
char	**map_dup(char **map);
int		count_collectibles(char **map);
int		check_map(char **map);
t_game	find_player(char **map);
void	free_map(char **map);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	exit_it(char *msg);
int		char_exists(const char *s, char c);
void	init_game(t_game *game);
void	init_mlx(t_game *game);
int		load_textures(t_game *game);
void	draw_map(t_game *game);
void	draw_title(t_game *game, char tile, int x, int y);
int		key_press(int keycode, t_game *game);
void	move_player(t_game *game, int dx, int dy);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	cleanup_game(t_game *game);
int		close_window(t_game *game);
int		check_av(int ac, char **av);

#endif