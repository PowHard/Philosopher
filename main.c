#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	philo;
	t_init	init;

	if (ft_check_error(ac, av) == 0)
		return (0);
	ft_init_arg(av, &init);
	ft_init_threads(&init, &philo);
	//printf("progam finish\n");
	//pthread_mutex_destroy(&philo.init.print);
}
