#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>   // read, write, close
#include <stdlib.h>   // malloc, free, exit
#include <fcntl.h>    // open
#include <stdio.h>    // ONLY for perror / strerror (not printf)
#include <errno.h>    // strerror
#include <math.h>     // math functions
#include <sys/time.h> // gettimeofday
#include "minilibx-linux/mlx.h"      // MiniLibX
#include "gnl/get_next_line.h"     // Get Next Line

typedef struct s_game
{
    /* ===== MiniLibX ===== */
    void    *mlx;       // MLX connection pointer
    void    *win;       // Window pointer

    /* ===== Map ===== */
    char    **map;      // Original map
    char    **map_copy; // Copy for flood fill
    int     width;      // Map width (tiles)
    int     height;     // Map height (tiles)

    /* ===== Player ===== */
    int     player_x;   // Player X position (tile index)
    int     player_y;   // Player Y position (tile index)

    /* ===== Game State ===== */
    int     collectibles;   // Total collectibles remaining
    int     moves;          // Number of player moves

    /* ===== Textures ===== */
    void    *img_wall;
    void    *img_floor;
    void    *img_player;
    void    *img_collect;
    void    *img_exit;

    /* ===== Image Size ===== */
    int     img_width;
    int     img_height;

}   t_game;

#define TILE_SIZE 32

/* *** *** *** *** */
/*    validate     */
/* *** *** *** *** */
int check_map_chars(char **map);
int is_rectangular(char **map);
int empty_line(char **map);
int len_same(char **map);
int check_walls(char **map);
int count_elements(char **map);
int	map_height(char **map);
int map_width(char **map);
int validate_map(char **map);
/* *** *** *** *** */
/*   flood_fill    */
/* *** *** *** *** */
char **map_dup(char **map);
int  count_collectibles(char **map);
void flood_fill(char **map, int x, int y, int *c_found, int *exit_found);
int  check_map(char **map);
t_game find_player(char **map);
void free_map(char **map);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	ft_putstr_fd(char *s, int fd);
void	exit_it(char *msg);
int	char_exists(const char *s, char c);
void init_game(char **map);
#endif