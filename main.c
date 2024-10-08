#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	philo;
	t_init	init;

	if (ft_check_error(ac, av) == 0)
		return (0);
	ft_init_arg(av, ac, &init, &philo);
	ft_init_mutex(&init/*, &philo*/);
	ft_init_threads(&init, &philo);
	ft_coordinate_action(&philo);
	ft_free_all(&init, &philo);
	//printf("progam finish\n");
	//pthread_mutex_destroy(&philo.init.print);
}
