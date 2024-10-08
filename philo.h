#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_init
{
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_meal;
	int	stop;
	int	full_meat;
	long start;
	pthread_mutex_t time_m;
	pthread_mutex_t sleep_m;
	pthread_mutex_t eat_m;
	pthread_mutex_t print_m;
}	t_init;

typedef struct s_philo
{
	pthread_t	thread;
	pthread_t	death_t;
	int			philo_id;
	int			meal_count;
	long	time_last_eat;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	l_fork;
	t_init		*init;

}	t_philo;
// /////////////////  check_error  ///////////////// //

int	is_digit(char **av);
int	ft_check_time(char **av);
int ft_nb_philo(int nb);
int	ft_check_error(int ac, char **av);

// /////////////////  utils  ///////////////// //

int long	ft_atol(const char *nptr);
void	ft_print(t_philo *philo, char *str);
void	ft_free_all(t_init *init, t_philo *philo);
long	ft_get_time();

// /////////////////  init  ///////////////// //

void	ft_init_arg(char **av, int ac, t_init *init, t_philo *philo);
void	ft_init_threads(t_init *init, t_philo *philo);
void	ft_init_mutex(t_init *init/*, t_philo *philo*/);
void	*ft_coordinate_action(void *arg);
void	ft_create_thread(t_init *init, t_philo *philo);

// /////////////////  action  ///////////////// //

void	*ft_take_fork(t_philo *philo);
void		ft_eat(t_init *init, t_philo *philo);
void	ft_msleep(long val);

// /////////////////  death  ///////////////// //

int	ft_nb_meal_max(t_init *init, t_philo *philo);
void	*ft_check_death(void *arg);


#endif