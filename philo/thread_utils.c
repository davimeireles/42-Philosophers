#include "philo.h"

void	init_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->total_philos)
	{
		pthread_create(&table->philo[i].thread, NULL, &dinner, &table->philo[i]);
		i++;
	}
	pthread_create(&table->checker, NULL, &check_status, table);
}

void	join_threads(t_table *table)
{
	int i;

	i = 0;
	pthread_join(table->checker, 0);
	while (i < table->total_philos)
	{
		pthread_join(table->philo[i].thread, 0);
		i++;
	}
	i = 0;
	while(i < table->total_philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		pthread_mutex_destroy(&table->philo[i].death);
		i++;
	}
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->mutex);
}

void	*check_status(void *data)
{
	t_table *table = (t_table *)data;
	while (1)
	{
		if (check_if_dead(table))
			return (NULL);
		if (check_if_ate(table))
			return (NULL);
	}
	return (NULL);
}

int	check_if_dead(t_table *table)
{
	int i;
	long current;

	i = 0;
	current = get_time();
	while(i < table->total_philos)
	{
		pthread_mutex_lock(&table->philo[i].death);
		pthread_mutex_lock(&table->mutex);
		if (current - table->philo->last_meal > table->time_to_die)
		{
			pthread_mutex_unlock(&table->mutex);
			print_status(&table->philo[i], "died.");
			pthread_mutex_lock(&table->mutex);
			table->dead = 1;
			pthread_mutex_unlock(&table->mutex);
			pthread_mutex_unlock(&table->philo[i].death);
			return (1);
		}
		pthread_mutex_unlock(&table->mutex);
		pthread_mutex_unlock(&table->philo[i].death);
		i++;
	}
	return (0);
}

int check_if_ate(t_table *table)
{
	if (table->minimum_meals == -1)
		return (0);
	pthread_mutex_lock(&table->mutex);
	if (table->all_full == table->minimum_meals)
	{
		pthread_mutex_unlock(&table->mutex);
		return (1);
	}
	pthread_mutex_unlock(&table->mutex);
	return (0);
}
