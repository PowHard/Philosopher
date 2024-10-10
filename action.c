/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estepere <estepere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:30:16 by estepere          #+#    #+#             */
/*   Updated: 2024/10/10 14:36:59 by estepere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_init *init, t_philo *philo)
{
	pthread_mutex_lock(&init->eat_m);
	ft_print(philo, "is eating 🥘");
	philo->meal_count++;
	philo->time_last_eat = ft_get_time();
	pthread_mutex_unlock(&init->eat_m);
	ft_msleep(init->time_to_eat);
}

void	ft_msleep(long val)
{
	usleep(val * 1000);
}

void	*ft_take_fork(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		usleep(100);
		pthread_mutex_lock(&philo->l_fork);
		ft_print(philo, "has taken a fork 🍴");
		pthread_mutex_lock(philo->r_fork);
		ft_print(philo, "has taken a fork 🍴");
	}
	else
	{
		usleep(50);
		pthread_mutex_lock(philo->r_fork);
		ft_print(philo, "has taken a fork 🍴");
		pthread_mutex_lock(&philo->l_fork);
		ft_print(philo, "has taken a fork 🍴");
	}
	return (NULL);
}

void	*ft_coordinate_action(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&philo->init->finish_m);
		if (philo->init->stop || philo->meal_count == philo->init->max_meal)
		{
			pthread_mutex_unlock(&philo->init->finish_m);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->init->finish_m);
		ft_take_fork(philo);
		ft_eat(philo->init, philo);
		pthread_mutex_unlock(&philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		ft_print(philo, "is sleeping 🛏️");
		ft_msleep(philo->time_sleep);
		ft_print(philo, "is thinking 💡");
	}
	return (NULL);
}
