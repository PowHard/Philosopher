#include "philo.h"

void	ft_init_arg(char **av, t_init *init)
{
	init->nb_philo = ft_atoi(av[1]);
	init->time_to_die = ft_atoi(av[2]);
	init->time_to_eat = ft_atoi(av[3]);
	init->time_to_sleep = ft_atoi(av[4]);
}
void	*ft_is_create(void *arg)
{
	int	nb;
	nb = *(int *)arg;
	printf("Philosopher %i has been created\n", nb);
	return (NULL);
}

void	ft_init_threads(t_init *init, t_philo *philo)
{
	int	i;

	i = 0;
	philo = malloc(sizeof(t_philo) * init->nb_philo);
	while (i < init->nb_philo)
	{
		philo[i].philo_id = i + 1;
		pthread_create(&philo[i].thread, NULL, ft_is_create, &philo[i].philo_id);
		i++;
	}
	i = 0;
	while (i < init->nb_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	free(philo);
}