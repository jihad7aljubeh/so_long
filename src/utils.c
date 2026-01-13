/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalju-be <jalju-be@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 02:34:46 by jihad             #+#    #+#             */
/*   Updated: 2026/01/04 20:16:40 by jalju-be         ###   ########.fr       */
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
	int		strlenl;
	int		extlen;
	char	*ext;
	int		i;

	if (ac != 2)
		return (0);
	if (!av[1])
		return (0);
	strlenl = ft_strlen(av[1]) - 1;
	extlen = 3;
	ext = ".ber";
	i = 0;
	while (av[1][strlenl - i] != 0 && extlen - i >= 0)
	{
		if (av[1][strlenl - i] != ext[extlen - i])
			return (0);
		i++;
	}
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
