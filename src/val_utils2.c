/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihad <jihad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 02:35:33 by jihad             #+#    #+#             */
/*   Updated: 2026/01/02 04:03:56 by jihad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_row(char *row)
{
	int	j;

	j = 0;
	while (row[j] && row[j] != '\n')
	{
		if (row[j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_walls(char **map)
{
	int	i;
	int	height;
	int	width;

	height = map_height(map);
	width = map_width(map);
	i = 0;
	while (map[i])
	{
		if (i == 0 || i == (height - 1))
		{
			if (!check_row(map[i]))
				return (0);
		}
		else
		{
			if (map[i][0] != '1' || map[i][width - 1] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

static void	count_row(char *row, int *p, int *e, int *c)
{
	int	j;

	j = 0;
	while (row[j])
	{
		if (row[j] == 'P')
			(*p)++;
		if (row[j] == 'E')
			(*e)++;
		if (row[j] == 'C')
			(*c)++;
		j++;
	}
}

int	count_elements(char **map)
{
	int	i;
	int	p;
	int	e;
	int	c;

	i = 0;
	p = 0;
	e = 0;
	c = 0;
	while (map[i])
	{
		count_row(map[i], &p, &e, &c);
		i++;
	}
	if (c < 1 || e != 1 || p != 1)
		return (0);
	return (1);
}
