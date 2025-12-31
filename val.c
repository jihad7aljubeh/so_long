#include "so_long.h"

int char_exists(const char *s, char c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int validate_map(char **map)
{
	if (!is_rectangular(map))
		return (0);
	if (empty_line(map))
		return (0);
	if (!len_same(map))
		return (0);
	if(!check_walls(map))
		return (0);
	if(!check_map_chars(map))
		return (0);
	if(!count_elements(map))
		return (0);
	if(!check_map(map))
		return (0);
	return (1);
}
