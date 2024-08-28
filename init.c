#include "philo.h"

void	ft_init_arg(char **av, t_init *init)
{
	init->nb_philo = ft_atoi(av[1]);
	init->time_to_die = ft_atoi(av[2]);
	init->time_to_eat = ft_atoi(av[3]);
	init->time_to_sleep = ft_atoi(av[4]);
}
void	ft_is_create(int nb)
{
	printf("Philosopher %i has been created", nb);
}

void	ft_init_threads(t_init *init)
{
	pthread_t thread;
	int	i;

	i = 0;
	while (i < init->nb_philo)
	{
		pthread_create(&thread, NULL, ft_is_create, i);
		i++;
	}
	while (i < init->nb_philo)
	{
		pthread_join(thread, NULL);
		i++;
	}
	printf("progam finish");
}