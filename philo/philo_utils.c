#include "philo.h"

void	init_table(t_table	*table, char **argv)
{
	table->total_philos = atoi(argv[1]);
	table->time_to_die = atol(argv[2]) * 1000;
	table->time_to_eat = atol(argv[3]) * 1000;
	table->time_to_sleep = atol(argv[4]) * 1000;
	if (argv[5])
		table->n_times_philo_must_eat = atoi(argv[5]);
	else
		table->n_times_philo_must_eat = -1;
	table->finish = false;
	table->start_time = get_time();
	table->current_time = 0;
}

void	init_philosophers(t_philosopher *philo, t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->total_philos)
	{
//		pthread_mutex_init(&philo->l_fork, 0);
		philo[i].id = i + 1;
		philo[i].meals = 0;
		philo[i].last_meal = 0;
		philo[i].table = table;
		if (philo[i].id == table->total_philos)
			philo[i].r_fork = &philo[0].l_fork;
		else
			philo[i].r_fork = &philo[i + 1].l_fork;
	}
}
