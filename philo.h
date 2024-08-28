#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

typedef struct s_init
{
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}	t_init;

// /////////////////  check_error  ///////////////// //

int	is_digit(char **av);
int	ft_check_time(char **av);
int ft_nb_philo(int nb);
int	ft_check_error(int ac, char **av);

// /////////////////  utils  ///////////////// //

int	ft_atoi(const char *nptr);

// /////////////////  init  ///////////////// //

void	ft_init_arg(char **av, t_init *init);

#endif