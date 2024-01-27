#include "philo.h"

void	*dinner(void *data)
{
	t_philosopher *philo;
	philo = (t_philosopher *) data;

	if (philo->table->total_philos == 1)
	{
		pthread_mutex_lock(philo->l_fork);
		if (print_status(philo,"has taken a fork"))
			return (NULL);
		pthread_mutex_unlock(philo->l_fork);
		return (NULL);
	}
	if (philo->id % 2 == 0) {
		usleep(10);
	}
	while(philo->table->dead == 0)
	{
		if (grab_forks(philo))
			return (NULL);
		if (go_eat(philo))
			return (NULL);
		if (go_sleep(philo))
			return (NULL);
		if (go_think(philo))
			return (NULL);
	}
	return (NULL);
}

int	grab_forks(t_philosopher *philo)
{
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
		if (print_status(philo, "has taken a fork"))
			return (1);
		pthread_mutex_lock(philo->r_fork);
		if (print_status(philo, "has taken a fork"))
			return (1);
	}
	return (0);
}

int go_eat(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->death);
	if (print_status(philo, "is eating."))
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(&philo->death);
		return (1);
	}
	pthread_mutex_unlock(&philo->death);
	pthread_mutex_lock(&philo->table->mutex);
	philo->last_meal = get_time();
	philo->meals++;
	if (philo->table->minimum_meals != -1)
	{
		if (philo->meals == philo->table->minimum_meals)
			philo->table->all_full++;
	}
	pthread_mutex_unlock(&philo->table->mutex);
	ft_usleep(philo->table->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (0);
}

int go_sleep(t_philosopher *philo)
{
	if (print_status(philo, "is sleeping"))
		return (1);
	ft_usleep(philo->table->time_to_sleep);
	return (0);
}

int	go_think(t_philosopher *philo)
{
	if (print_status(philo, "is thinking"))
		return (1);
	return (0);
}
