#include "philo.h"

void	ft_init_arg(char **av, int ac, t_init *init, t_philo *philo)
{
	init->nb_philo = ft_atol(av[1]);
	init->time_to_die = ft_atol(av[2]);
	init->time_to_eat = ft_atol(av[3]);
	init->time_to_sleep = ft_atol(av[4]);
	init->full_meat = 0;
	init->stop = 0;
	philo->meal_count = 0;
	if (ac > 5)
		init->max_meal = ft_atol(av[5]);
	else
		init->max_meal = -1;
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
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->init->stop == 1)
			return (NULL);
		if (philo->init->max_meal == philo->init->max_meal)
			ft_take_last_meat(philo);
		ft_take_fork(philo);
		ft_eat(philo->init, philo);
		pthread_mutex_unlock(&philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		ft_print(philo, "is sleeping 🛏️");
		ft_msleep(philo->init->time_to_sleep);
		ft_print(philo, "is thinking 💡");
	}
	return (NULL);
}
// NEED TO COPY TIME_TO_EAT AND TIME_TO_SLEEP FOR EACH PHILO and put mutex to do this.

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
	pthread_create(&philo->death_t, NULL, ft_check_death, &philo);
	while (i < init->nb_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}