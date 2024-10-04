#include "philo.h"

int long	ft_atol(const char *nptr)
{
	int long	i;
	int long	sign;
	int long	result;

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
	usleep(10);
	pthread_mutex_unlock(&philo.init->print);
}
void	ft_free_all(t_init *init, t_philo *philo)
{
	int i;

	i = 0;
	while (i < init->nb_philo)
	{
		pthread_mutex_destroy(&philo[i].l_fork);
		i++;
	}
	free(philo);
	free(init);
}

long long	ft_get_time()
{
	struct timeval tv;
	long			res;

	if (gettimeofday(&tv, NULL) == -1)
		return (EXIT_FAILURE);
	res = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (res);
}