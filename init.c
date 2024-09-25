#include "philo.h"

void	ft_init_arg(char **av, t_init *init)
{
	init->nb_philo = ft_atoi(av[1]);
	init->time_to_die = ft_atoi(av[2]);
	init->time_to_eat = ft_atoi(av[3]);
	init->time_to_sleep = ft_atoi(av[4]);
}
void	*ft_take_fork(void *arg)
{
	t_philo	philo;
	philo = *(t_philo *)arg;
	if (philo.philo_id % 2 == 0)
	{
		pthread_mutex_lock(&philo.r_fork);
		// ft_print
		pthread_mutex_lock(&philo.l_fork);
		// ft_print
		//ft_eat
		pthread_mutex_unlock(&philo.r_fork);
		pthread_mutex_unlock(&philo.l_fork);
	}
	else
	{
		pthread_mutex_lock(&philo.l_fork);
		// ft_print
		pthread_mutex_lock(&philo.r_fork);
		// ft_print
		//ft_eat
		pthread_mutex_unlock(&philo.l_fork);
		pthread_mutex_unlock(&philo.r_fork);
	}
	rerurn (NULL);
}

//fourchette de droite est la fourchette alors que celle de gauche est un pointeur sur une fourchette (la fourchette 
// de droite du précédent)
//
// ordre pair => droite puis gauche(*)
// ordre impair => gauche(*) puis droite pour éviter deadlock
// 
// 
// 


void	ft_init_threads(t_init *init, t_philo *philo)
{
	int	i;

	i = 0;
	philo = malloc(sizeof(t_philo) * init->nb_philo);
	pthread_mutex_init(&philo->init.print, NULL);
	while (i < init->nb_philo)
	{
		philo[i].philo_id = i + 1;
		pthread_create(&philo[i].thread, NULL, ft_take_fork, &philo[i]);
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