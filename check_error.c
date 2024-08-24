#include "philo.h"

int	is_digit(char **av)
{
	int	i;
	int j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_time(char **av)
{
	int i;

	i = 2;
	while (i < 5)
	{
		if (ft_atoi(av[i]) < 60)
			return (0);
		i++;
	}

	return (1);
}
int ft_nb_philo(int nb)
{
	return (nb >= 1 && nb <= 200);
}

int ft_display_error(char *str)
{
	printf("%s\n", str);
	return (0);
}

int	ft_check_error(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		ft_display_error("ERROR, you must have 4 or 5 input");
	if (is_digit(av) == 0)
		ft_display_error("ERROR, put only positive digit");
	if (ft_check_time(av) == 0)
		ft_display_error("ERROR, the time must be higher than 60ms");
	if (ft_nb_philo(ft_atoi(av[1])) == 0)
		ft_display_error("ERROR, number of philosopher must be between 1 and 200 include");
	if (ac == 6)
	{
		if (ft_atoi(av[5]) == 0)
			ft_display_error("ERROR, the philosopher must eat minimum one time");
	}
	return (1);
}
