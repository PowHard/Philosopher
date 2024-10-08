#include "philo.h"


void	ft_eat(t_init *init, t_philo *philo)
{
	pthread_mutex_lock(&init->eat_m);
	philo->time_last_eat = ft_get_time();
	ft_print(philo, "is eating 🥘");
	pthread_mutex_unlock(&init->eat_m);
	ft_msleep(init->time_to_eat);
	// pthread_mutex_lock(&init->sleep_m);
	// pthread_mutex_unlock(&init->sleep_m);
}

void	ft_msleep(long val)
{
	// printf("sleep time = %ld\n", val);
	usleep(val * 1000);
	// printf("sleep time = %ld\n", val);
}

void	*ft_take_fork(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		usleep(100);
		pthread_mutex_lock(&philo->l_fork);
		// printf("philo %i adress left %p\n", philo->philo_id, (void *)&(philo->l_fork));
		ft_print(philo, "has taken a fork 🍴");
		// printf("philo %i has taken a fork left🍴\n", philo->philo_id);
		pthread_mutex_lock(philo->r_fork);
		// printf("philo %i adress right %p\n", philo->philo_id, (void *)&(philo->r_fork));
		ft_print(philo, "has taken a fork 🍴");

		// printf("philo %i has taken a fork right🍴\n", philo->philo_id);
	}
	else
	{
		usleep(50);
		// ft_msleep(1);
		pthread_mutex_lock(philo->r_fork);
		// printf("philo %i adress right %p\n", philo->philo_id, (void *)&(philo->r_fork));
		ft_print(philo, "has taken a fork 🍴");
		// printf("philo %i has taken a fork right🍴\n", philo->philo_id);
		pthread_mutex_lock(&philo->l_fork);
		ft_print(philo, "has taken a fork 🍴");
		// printf("philo %i adress left %p\n", philo->philo_id, (void *)&(philo->l_fork));

		// printf("philo %i has taken a fork left🍴\n", philo->philo_id);
	}

	return (NULL);
}
