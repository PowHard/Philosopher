#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_init	init;

	if (ft_check_error(ac, av) == 0)
		return (0);
	ft_init_arg(av, ac, &init);
	ft_init_mutex(&init/*, &philo*/);
	if (init.nb_philo == 1)
	{
		printf("%li Philosopher 1 has taken a fork 🍴\n", ft_get_time() - init.start);
		printf("%i Philosopher 1 died\n", init.time_to_die);
		// printf("%d Philosopher %i died\n", init.time_to_die, philo.philo_id);
		return (0);
	}
	philo = malloc(sizeof(t_philo) * init.nb_philo);
	ft_init_threads(&init, philo);
	ft_free_all(&init, philo);
	
}
