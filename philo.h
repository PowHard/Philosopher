#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct s_init
{
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	pthread_mutex_t print;
}	t_init;

typedef struct s_philo
{
	pthread_t	thread;
	int			philo_id;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	*l_fork;
	t_init		*init;

}	t_philo;
// /////////////////  check_error  ///////////////// //

int	is_digit(char **av);
int	ft_check_time(char **av);
int ft_nb_philo(int nb);
int	ft_check_error(int ac, char **av);

// /////////////////  utils  ///////////////// //

int	ft_atoi(const char *nptr);
void	ft_print(t_philo philo, char *str);

// /////////////////  init  ///////////////// //

void	ft_init_arg(char **av, t_init *init);
void	ft_init_threads(t_init *init, t_philo *philo);
void	*ft_take_fork(void *arg);

#endif