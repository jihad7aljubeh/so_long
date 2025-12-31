#include "so_long.h"
#include <stdio.h>
int check_map_chars(char **map)
{
	int			i;
	int			j;
	const char	*valid_chars;

	if (!map)
		return (0);

	valid_chars = "01CEP";
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n')
			{
				j++;
				continue;
			}
			if (!char_exists(valid_chars, map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int is_rectangular(char **map)
{
	int height;
	int width;
	int i;
	int c = 0;

	height = map_height(map);
	width = map_width(map);
	i = 0;
	while (i < height - 1)
	{
		c++;
		if (ft_strlen(map[i]) == width)
			i++;
		else
			return (0);
	}
	return (1);
}
int empty_line(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] == '\n' || map[i][0] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int len_same(char **map)
{
	int i;
	t_game game;
	game.width = map_width(map);
	game.height = map_height(map);
	i = 1;
	while(i < game.height - 1)
	{
		if(ft_strlen(map[i]) != game.width)
			return(0);
		i++;
	}
	return (1);
}
