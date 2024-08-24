#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>

// /////////////////  check_error ///////////////// //

int	is_digit(char **av);
int	ft_check_time(char **av);
int ft_nb_philo(int nb);
int	ft_check_error(int ac, char **av);

// /////////////////  utils ///////////////// //

int	ft_atoi(const char *nptr);

#endif