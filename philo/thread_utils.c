#include "philo.h"

void	creat_threads(t_philosopher *philo)
{
	int	i;

	i = -1;
	while (++i < philo->table->total_philos)
		pthread_create(&philo[i].thread, NULL, &dinner, &philo[i]);
	i = -1;
	while (++i < philo->table->total_philos)
		pthread_join(philo[i].thread, 0);
}

void	threads(t_philosopher *philo)
{
	creat_threads(philo);
}

