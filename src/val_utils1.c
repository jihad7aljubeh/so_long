/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihad <jihad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 02:35:27 by jihad             #+#    #+#             */
/*   Updated: 2026/01/02 04:04:12 by jihad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_chars(char **map)
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
				continue ;
			}
			if (!char_exists(valid_chars, map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_rectangular(char **map)
{
	int	height;
	int	width;
	int	i;
	int	line_len;

	height = map_height(map);
	width = map_width(map);
	i = 0;
	while (i < height)
	{
		line_len = ft_strlen(map[i]);
		if (map[i][line_len - 1] == '\n')
			line_len--;
		if (line_len != width)
			return (0);
		i++;
	}
	return (1);
}

int	empty_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] == '\n' || map[i][0] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	len_same(char **map)
{
	int	i;
	int	width;
	int	height;
	int	line_len;

	width = map_width(map);
	height = map_height(map);
	i = 1;
	while (i < height - 1)
	{
		line_len = ft_strlen(map[i]);
		if (map[i][line_len - 1] == '\n')
			line_len--;
		if (line_len != width)
			return (0);
		i++;
	}
	return (1);
}

int	char_exists(const char *s, char c)
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
