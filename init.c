#include "philo.h"

void	ft_init_arg(char **av, t_init *init)
{
	init->nb_philo = ft_atol(av[1]);
	init->time_to_die = ft_atol(av[2]);
	init->time_to_eat = ft_atol(av[3]);
	init->time_to_sleep = ft_atol(av[4]);
}

void	ft_init_mutex(t_init *init/*, t_philo *philo*/)
{
	pthread_mutex_init(&init->print_m, NULL);
	pthread_mutex_init(&init->eat_m, NULL);
	pthread_mutex_init(&init->sleep_m, NULL);
	pthread_mutex_init(&init->time_m, NULL);
}

void	*ft_coordinate_action(void *arg)
{
	// int i;
	t_philo	*philo;

	// i = 0;
	philo = (t_philo *)arg;
	while (1)
	{
		ft_take_fork(philo);
		// i++;
	}
	return (NULL);
}
void	ft_init_threads(t_init *init, t_philo *philo)
{
	int	i;

	i = 0;
	init->start = ft_get_time();
	printf("start = %ld\n", init->start);
	philo = malloc(sizeof(t_philo) * init->nb_philo);
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
		// printf("Philo %d: l_fork = %p, r_fork = %p\n", 
		// 	philo[i].philo_id, (void*)&philo[i].l_fork, (void*)philo[i].r_fork);
		i++;
	}
	ft_create_thread(init, philo);
}

void	ft_create_thread(t_init *init, t_philo *philo)
{
	int	i = 0;

	i = 0;
	while (i < init->nb_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, ft_coordinate_action, &philo[i]) != 0)
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