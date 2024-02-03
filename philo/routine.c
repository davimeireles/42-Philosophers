/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:32:31 by dmeirele          #+#    #+#             */
/*   Updated: 2024/01/29 15:34:53 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dinner(void *data)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)data;
	if (philo->table->total_philos == 1)
	{
		pthread_mutex_lock(philo->l_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_unlock(philo->l_fork);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (go_think(philo))
			return (NULL);
		if (grab_forks(philo))
			return (NULL);
		if (go_eat(philo))
			return (NULL);
		if (go_sleep(philo))
			return (NULL);
	}
	return (NULL);
}

int	grab_forks(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->table->mutex);
	if (philo->table->dead >= 1
		|| philo->table->all_full == philo->table->total_philos)
	{
		pthread_mutex_unlock(&philo->table->mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->mutex);
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->r_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->l_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		print_status(philo, "has taken a fork");
	}
	return (0);
}

int	go_eat(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->table->mutex);
	if (philo->table->dead >= 1
		|| philo->table->all_full == philo->table->total_philos)
	{
		pthread_mutex_unlock(&philo->table->mutex);
		free_forks(philo);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->mutex);
	pthread_mutex_lock(&philo->death);
	philo->last_meal = get_time();
	print_status(philo, "is eating");
	pthread_mutex_lock(&philo->table->mutex);
	philo->meals++;
	if (philo->table->minimum_meals != -1)
	{
		if (philo->meals == philo->table->minimum_meals)
			philo->table->all_full++;
	}
	pthread_mutex_unlock(&philo->table->mutex);
	pthread_mutex_unlock(&philo->death);
	ft_usleep(philo->table->time_to_eat);
	free_forks(philo);
	return (0);
}

int	go_sleep(t_philosopher *philo)
{
	usleep(1000);
	pthread_mutex_lock(&philo->table->mutex);
	if (philo->table->dead >= 1
		|| philo->table->all_full == philo->table->total_philos)
	{
		pthread_mutex_unlock(&philo->table->mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->mutex);
	print_status(philo, "is sleeping");
	ft_usleep(philo->table->time_to_sleep);
	return (0);
}

int	go_think(t_philosopher *philo)
{
	usleep(1000);
	pthread_mutex_lock(&philo->table->mutex);
	if (philo->table->dead >= 1
		|| philo->table->all_full == philo->table->total_philos)
	{
		pthread_mutex_unlock(&philo->table->mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->mutex);
	print_status(philo, "is thinking");
	usleep(1000);
	return (0);
}
