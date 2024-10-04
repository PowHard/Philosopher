#include "philo.h"

void	ft_init_arg(char **av, t_init *init)
{
	init->nb_philo = ft_atol(av[1]);
	init->time_to_die = ft_atol(av[2]);
	init->time_to_eat = ft_atol(av[3]);
	init->time_to_sleep = ft_atol(av[4]);
	pthread_mutex_init(&init->print, NULL);
}
void	*ft_take_fork(void *arg)
{
	int i;
	t_philo	philo;

	i = 0;
	philo = *(t_philo *)arg;
	while (i < 5)
	{
		if (philo.philo_id % 2 == 0/*!= philo.init->nb_philo*/)
		{
			pthread_mutex_lock(&philo.l_fork);
			// ft_print(philo, "has taken a fork left🍴");
			printf("philo %i has taken a fork left🍴\n", philo.philo_id);
			pthread_mutex_lock(philo.r_fork);
			// ft_print(philo, "has taken a fork right🍴");
			printf("philo %i has taken a fork right🍴\n", philo.philo_id);
		}
		else
		{
			usleep(10);
			pthread_mutex_lock(philo.r_fork);
			// ft_print(philo, "has taken a fork right🍴");
			printf("philo %i has taken a fork right🍴\n", philo.philo_id);
			pthread_mutex_lock(&philo.l_fork);
			// ft_print(philo, "has taken a fork left🍴");
			printf("philo %i has taken a fork left🍴\n", philo.philo_id);
		}
		// ft_print(philo, "is eating");
		usleep(1000);
		pthread_mutex_unlock(&philo.l_fork);
		// ft_print(philo, "unlock left");
		printf("philo %i unlock left\n", philo.philo_id);
		pthread_mutex_unlock(philo.r_fork);
		// ft_print(philo, "unlock right");
		printf("philo %i unlock right\n", philo.philo_id);
		usleep(100);
		// i++;
	}
	return (NULL);
}

void	ft_init_threads(t_init *init, t_philo *philo)
{
	int	i;

	i = 0;
	init->start = ft_get_time();
	philo = malloc(sizeof(t_philo) * init->nb_philo);
	// pthread_mutex_init(&init->print, NULL);
	while (i < init->nb_philo)
	{
		philo[i].philo_id = i + 1;
		philo[i].init = init;
		philo[i].r_fork = NULL;
		pthread_mutex_init(&philo[i].l_fork, NULL);
		if (i == init->nb_philo - 1)
			philo[i].r_fork = &philo[0].l_fork;
		else
			philo[i].r_fork = &philo[i + 1].l_fork;
		// pthread_create(&philo[i].thread, NULL, ft_take_fork, &philo[i]);
		i++;
	}
	i = 0;
	while (i < init->nb_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, ft_take_fork, &philo[i]) != 0)
			printf("philo fucked up");
		i++;
	}
	i = 0;
	while (i < init->nb_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}
