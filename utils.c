#include "so_long.h"

void free_map(char **map)
{
    int i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

int	check_av(int ac, char **av)
{
	if(ac != 2)
		return (0);
	if(!(ft_strnstr(av[1],".ber",ft_strlen(av[1]))))
		return (0);
	if(!av[1])
		return (0);
	return (1);
}
void	exit_it(char *msg)
{
	if(msg)
		ft_putstr_fd(msg,2);
	exit (1);
}
void print_map(char **map)
{
	int i = 0;
	while(map[i])
	{
		printf("%s",map[i]);
		i++;
	}
}
