/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:34:55 by dmeirele          #+#    #+#             */
/*   Updated: 2024/01/29 14:49:04 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->total_philos)
	{
		pthread_create(&table->philo[i].thread, NULL, &dinner,
			&table->philo[i]);
		i++;
	}
	pthread_create(&table->checker, NULL, &check_status, table);
}

void	join_threads(t_table *table)
{
	int	i;

	i = 0;
	pthread_join(table->checker, 0);
	while (i < table->total_philos)
	{
		pthread_join(table->philo[i].thread, 0);
		i++;
	}
}

void	*check_status(void *data)
{
	t_table	*table;

	table = (t_table *)data;
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
	int		i;
	long	current;

	i = 0;
	current = get_time();
	while (i < table->total_philos)
	{
		pthread_mutex_lock(&table->philo[i].death);
		if (current - table->philo[i].last_meal >= table->time_to_die)
		{
			print_status(&table->philo[i], "died");
			pthread_mutex_lock(&table->mutex);
			table->dead = 1;
			pthread_mutex_unlock(&table->mutex);
			pthread_mutex_unlock(&table->philo[i].death);
			return (1);
		}
		pthread_mutex_unlock(&table->philo[i].death);
		i++;
	}
	return (0);
}

int	check_if_ate(t_table *table)
{
	if (table->minimum_meals == -1)
		return (0);
	pthread_mutex_lock(&table->mutex);
	if (table->all_full == table->total_philos)
	{
		pthread_mutex_unlock(&table->mutex);
		return (1);
	}
	pthread_mutex_unlock(&table->mutex);
	return (0);
}
