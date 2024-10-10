/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estepere <estepere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:31:20 by estepere          #+#    #+#             */
/*   Updated: 2024/10/10 12:39:30 by estepere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_time_death(t_init *init, t_philo *philo)
{
	long	time;

	pthread_mutex_lock(&init->eat_m);
	time = ft_get_time() - philo->time_last_eat;
	if (time > init->time_to_die)
	{
		pthread_mutex_unlock(&init->eat_m);
		return (1);
	}
	pthread_mutex_unlock(&init->eat_m);
	return (0);
}

void	*ft_check_death(void *arg)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)arg;
	i = 0;
	while (1)
	{
		i = 0;
		while (i < philo->init->nb_philo)
		{
			if (ft_check_time_death(philo[i].init, &philo[i]) == 1)
			{
				ft_print(philo, "died");
				pthread_mutex_lock(&philo->init->finish_m);
				philo->init->stop++;
				pthread_mutex_unlock(&philo->init->finish_m);
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}
