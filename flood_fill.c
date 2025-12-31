#include "so_long.h"

/* ================= MAP DUPLICATION ================= */

char **map_dup(char **map)
{
    int     i;
    int     height;
    char    **map_copy;

    if (!map)
        return (NULL);

    height = 0;
    while (map[height])
        height++;

    map_copy = malloc(sizeof(char *) * (height + 1));
    if (!map_copy)
        return (NULL);

    i = 0;
    while (i < height)
    {
        map_copy[i] = ft_strdup(map[i]);
        if (!map_copy[i])
        {
            while (i > 0)
                free(map_copy[--i]);
            free(map_copy);
            return (NULL);
        }
        i++;
    }
    map_copy[height] = NULL;
    return (map_copy);
}

/* ================= COUNT COLLECTIBLES ================= */

int count_collectibles(char **map)
{
    int i;
    int j;
    int c;

    i = 0;
    c = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'C')
                c++;
            j++;
        }
        i++;
    }
    return (c);
}

/* ================= FIND PLAYER ================= */

t_game find_player(char **map)
{
    t_game player;
    int i;
    int j;

    player.player_x = -1;
    player.player_y = -1;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
            {
                player.player_x = j;
                player.player_y = i;
                return (player);
            }
            j++;
        }
        i++;
    }
    return (player);
}

/* ================= FLOOD FILL ================= */

void flood_fill(char **map, int x, int y, int *c_found, int *exit_found)
{
    if (y < 0 || x < 0 || !map[y] || !map[y][x])
        return;
    if (map[y][x] == '1' || map[y][x] == 'F')
        return;

    if (map[y][x] == 'C')
        (*c_found)++;
    if (map[y][x] == 'E')
        *exit_found = 1;

    map[y][x] = 'F';

    flood_fill(map, x + 1, y, c_found, exit_found);
    flood_fill(map, x - 1, y, c_found, exit_found);
    flood_fill(map, x, y + 1, c_found, exit_found);
    flood_fill(map, x, y - 1, c_found, exit_found);
}

/* ================= PATH VALIDATION ================= */

int check_map(char **map)
{
    char    **map_cpy;
    t_game  player;
    int     total_c;
    int     found_c;
    int     exit_found;

    if (!map)
        return (0);

    total_c = count_collectibles(map);
    found_c = 0;
    exit_found = 0;

    map_cpy = map_dup(map);
    if (!map_cpy)
        return (0);

    player = find_player(map);
    if (player.player_x == -1 || player.player_y == -1)
    {
        free_map(map_cpy);
        return (0);
    }

    flood_fill(map_cpy, player.player_x, player.player_y,
               &found_c, &exit_found);

    free_map(map_cpy);

    if (found_c != total_c)
        return (0);
    if (!exit_found)
        return (0);

    return (1);
}
