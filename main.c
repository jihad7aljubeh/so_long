#include "so_long.h"

void init_game(t_game *game)
{
    game->mlx = NULL;
    game->win = NULL;

    game->moves = 0;

    game->height = map_height(game->map);
    game->width = map_width(game->map);

    game->player_x = -1;
    game->player_y = -1;

    game->img_wall = NULL;
    game->img_floor = NULL;
    game->img_player = NULL;
    game->img_exit = NULL;
    game->img_collect = NULL;
}


char **read_map(int ac, char **av)
{
    int     fd;
    char    **map = NULL;
    int     max_lines = 1024; // Adjust as needed
    char    *line;
    int     j = 0;

    if (!check_av(ac, av))
        exit_it("Error: Invalid arguments.\n");

    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        exit_it("Error\n");

    map = malloc(sizeof(char *) * max_lines);
    if (!map)
        exit_it("Error: Memory allocation failed.\n");

    while ((line = get_next_line(fd)))
    {
        map[j] = line;
        j++;
    }
    map[j] = NULL;

    if (!validate_map(map))
        exit_it("Error\n");

    return map;
}

int main(int ac, char **av)
{
	t_game  game;
    char **map;
    
    map = read_map(ac, av);

    game.map = map;
    init_game(&game);
    init_mlx(&game);
    load_textures(&game);
    draw_map(&game);

    mlx_hook(game.win, 2, 1L << 0, key_press, &game);
    mlx_hook(game.win, 17, 0, close_window, &game);
    mlx_loop(game.mlx);

}