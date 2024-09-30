#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
void	ft_print(t_philo philo, char *str)
{
	pthread_mutex_lock(&philo.init->print);
	printf("Philosopher %i %s\n", philo.philo_id, str);
	pthread_mutex_unlock(&philo.init->print);
}
void	ft_free_all(t_init *init, t_philo *philo)
{
	int i;

	i = 0;
	while (i < init->nb_philo)
	{
		pthread_mutex_destroy(&philo[i].r_fork);
		i++;
	}
	free(philo);
	free(init);
}