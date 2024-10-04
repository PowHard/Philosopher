#include "philo.h"

void	ft_init_arg(char **av, t_init *init)
{
	// replace by atol
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
	// if (philo.philo_id % 2 == 0)
	// 	usleep(100);
	while (i < 5)
	{
		// ft_print(philo, "tour");
		// printf(" %d\n", i);
		if (philo.philo_id % 2 == 0/*!= philo.init->nb_philo*/)
		{
			// usleep(200);
			pthread_mutex_lock(&philo.l_fork);
			ft_print(philo, "has taken a fork left🍴");
			pthread_mutex_lock(philo.r_fork);
			ft_print(philo, "has taken a fork right🍴");
			// check if die with last_eat
			//ft_eat, print he is eating.. put take a fork in ft_eat.
			// ft_sleep 
			// données dans terminal donné en milisec et Usleep en micro voir pour gettimeofday
			// gettimeofday pour détecter mort philololo
		}
		else
		{
			pthread_mutex_lock(philo.r_fork);
			ft_print(philo, "has taken a fork right🍴");
			pthread_mutex_lock(&philo.l_fork);
			ft_print(philo, "has taken a fork left🍴");
			//ft_eat
		}
		ft_print(philo, "is eating");
		// usleep(100); // eat
		pthread_mutex_unlock(&philo.l_fork);
		ft_print(philo, "unlock left");
		pthread_mutex_unlock(philo.r_fork);
		ft_print(philo, "unlock right");
		// usleep(100);
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
