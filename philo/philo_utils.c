#include "philo.h"

void	init_table(t_table	*table, char **argv)
{
	table->total_philos = atoi(argv[1]);
	table->time_to_die = atol(argv[2]);
	table->time_to_eat = atol(argv[3]);
	table->time_to_sleep = atol(argv[4]);
	if (argv[5])
		table->minimum_meals = atoi(argv[5]);
	else
		table->minimum_meals = -1;
	table->all_full = 0;
	table->dead = 0;
	table->start_time = get_time();
	pthread_mutex_init(&table->print, 0);
	pthread_mutex_init(&table->mutex, 0);
	table->forks = init_forks(table->total_philos);
	table->philo = init_philosophers(table);
}

pthread_mutex_t *init_forks(int total_philos)
{
	int i;
	pthread_mutex_t	*forks;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * total_philos);
	if (!forks)
		return (NULL);
	while(i < total_philos)
	{
		pthread_mutex_init(&forks[i], 0);
		i++;
	}
	return (forks);
}

t_philosopher	*init_philosophers(t_table *table)
{
	int	i;
	t_philosopher *philo;

	philo = malloc(sizeof(t_philosopher) * table->total_philos);
	if (!philo)
		return (NULL);
	i = 0;
	while (i < table->total_philos)
	{
		philo[i].id = i + 1;
		philo[i].meals = 0;
		philo[i].last_meal = get_time();
		philo[i].l_fork = &table->forks[i];
		if (table->total_philos != 1) {
			philo[i].r_fork = &table->forks[(i + 1) % table->total_philos];
		}
		philo[i].table = table;
		pthread_mutex_init(&philo[i].death, 0);
		i++;
	}
	return (philo);
}
