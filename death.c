#include "philo.h"

// int	ft_nb_meal_max(t_init *init, t_philo *philo)
// {
// 	if (philo->meal_count == init->max_meal)
// 	{
// 		ft_print(philo, "has taken his last meal");
// 		return (1);
// 	}
// 	return (0);
// }
int	ft_check_time_death(t_init *init, t_philo *philo)
{
	long time;

	if (philo->time_last_eat == init->start)
		return (0);
	time = ft_get_time() - philo->time_last_eat;
	if (time > init->time_to_die)
		return (1);
	return (0);
}

void	*ft_check_death(void *arg)
{
	int	i;
	t_philo	*philo;

	philo = (t_philo *)arg;
	i = 0;
	while (1)
	{
		i = 0;
		while (i < philo->init->nb_philo)
		{
			// if (ft_nb_meal_max(philo[i].init, &philo[i]) == 1)
			// 	philo->init->full_meat++;
			if (ft_check_time_death(philo[i].init, &philo[i]) == 1)
			{
				ft_print(philo, "died");
				philo->init->stop++;
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}