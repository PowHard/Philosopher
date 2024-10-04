#include "philo.h"

void	ft_init_arg(char **av, t_init *init)
{
	// replace by atol
	init->nb_philo = ft_atol(av[1]);
	init->time_to_die = ft_atol(av[2]);
	init->time_to_eat = ft_atol(av[3]);
	init->time_to_sleep = ft_atol(av[4]);
}
void	*ft_take_fork(void *arg)
{
	int i;
	t_philo	philo;

	i = 0;
	philo = *(t_philo *)arg;
	if (philo.philo_id % 2 == 0)
		usleep(100);
	while (i < 5)
	{
		if (philo.philo_id != philo.init->nb_philo)
		{
			pthread_mutex_lock(philo.l_fork);
			ft_print(philo, "has taken a fork left🍴");
			pthread_mutex_lock(&philo.r_fork);
			ft_print(philo, "has taken a fork right🍴");
			// check if die with last_eat
			//ft_eat, print he is eating.. put take a fork in ft_eat.
			// ft_sleep 
			// données dans terminal donné en milisec et Usleep en micro voir pour gettimeofday
			// gettimeofday pour détecter mort philololo
			// usleep(1000);
			pthread_mutex_unlock(philo.l_fork);
			printf("unlock left\n");
			pthread_mutex_unlock(&philo.r_fork);
			printf("unlock right\n");

		}
		else
		{
			pthread_mutex_lock(philo.l_fork);
			ft_print(philo, "has taken a fork left🍴");
			pthread_mutex_lock(&philo.r_fork);
			ft_print(philo, "has taken a fork right🍴");
			//ft_eat
			pthread_mutex_unlock(philo.l_fork);
			printf("unlock left\n");
			pthread_mutex_unlock(&philo.r_fork);
			printf("unlock right\n");

		}
		usleep(100);
		i++;
	}
	return (NULL);
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
	init->start = ft_get_time();
	philo = malloc(sizeof(t_philo) * init->nb_philo);
	pthread_mutex_init(&init->print, NULL);
	while (i < init->nb_philo)
	{
		philo[i].philo_id = i + 1;
		philo[i].init = init;
		pthread_mutex_init(&philo->r_fork, NULL);
		if (i == 0)
			philo[i].l_fork = &philo[init->nb_philo - 1].r_fork;
		else
			philo[i].l_fork = &philo[i - 1].r_fork;
		pthread_create(&philo[i].thread, NULL, ft_take_fork, &philo[i]);
		i++;
	}
	i = 0;
	while (i < init->nb_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}
