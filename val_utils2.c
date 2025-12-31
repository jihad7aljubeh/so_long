#include "so_long.h"

int check_walls(char **map)
{
	int i;
	int j;
	t_game  game;
    game.height = map_height(map);
	game.width = map_width(map);
	i = 0;
	while(map[i])
	{
		j = 0;
		if(i == 0 || i == (game.height - 1))
		{
			while(map[i][j])
			{
				if(map[i][j] == '0')
					return (0);
				j++;
			}
		}
		else
		{
			if(map[i][0] == '0' || map[i][game.width - 1] == '0')
				return(0);
		}
		i++;
	} 
	return (1);
}

int count_elements(char **map)
{
	int i;
	int p;
	int e;
	int c;
	int j;

	i = 0;
	p = 0;
	e = 0;
	c = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == 'P')
				p++;
			if(map[i][j] == 'E')
				e++;
			if(map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if(c < 1 || e != 1 || p != 1)
		return  (0);
	return (1);
}

int	map_height(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int map_width(char **map)
{
	return (ft_strlen(map[0]));
}
