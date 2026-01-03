/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalju-be <jalju-be@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 02:34:46 by jihad             #+#    #+#             */
/*   Updated: 2026/01/03 17:27:34 by jalju-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	check_av(int ac, char **av)
{
	if (ac != 2)
		return (0);
	if (!(ft_strnstr(av[1], ".ber'\0'", ft_strlen(av[1]))))
		return (0);
	if (!av[1])
		return (0);
	return (1);
}

void	exit_it(char *msg)
{
	if (msg)
		ft_putstr_fd(msg, 2);
	exit(1);
}

int	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	map_width(char **map)
{
	int	len;

	len = ft_strlen(map[0]);
	if (map[0][len - 1] == '\n')
		len--;
	return (len);
}
