#include "philo.h"

void	*dinner(void *data)
{
	t_philosopher *philo;
	philo = (t_philosopher *) data;

	while (1)
	{
	printf("Philosopher ID is %d\nPhilosopher Meals is %ld\n",philo->id,philo->meals);
	sleep(5);
	}
	/*	printf("Total Philosophers is %d\nTime to Die is %ld\nTime to Eat is %ld\n"
		   "Time to Sleep is %ld\nEach Philosopher Must Eat %d Times\n"
		   "Start Time is %ld\nCurrent Time is %ld\n",philo->table->total_philos,philo->table->time_to_die,philo->table->time_to_eat,
		   philo->table->time_to_sleep,philo->table->n_times_philo_must_eat,philo->table->start_time,philo->table->current_time);*/
/*	while(!get_mutex_bool(philo, &philo->table->finish))
	{
		to_eat(philo);
		sleep(2);
		to_sleep(table);
		sleep(2);
		to_think(table);
		sleep(2);
	}*/
	return (0);
}

/*
void	to_eat(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	pthread_mutex_lock(philo->r_fork);
	printf("Philosopher %d eating.\n",philo->id);
	usleep(philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
*/

/*
void	to_think(t_philosopher *philo)
{
	int i = 0;
	pthread_mutex_lock(&table->access);
	while (i < table->n_philosophers)
	{
		printf("Philosopher %d thinking.\n",table->philosophers[i].id);
		i++;
	}
	pthread_mutex_unlock(&table->access);
}

void	to_sleep(t_philosopher *philo)
{
	int i = 0;
	pthread_mutex_lock(&table->access);
	while (i < table->n_philosophers)
	{
		printf("Philosopher %d sleeping.\n",table->philosophers[i].id);
		i++;
	}
	pthread_mutex_unlock(&table->access);
}
*/

/*
		printf("Total Philosophers around the table is %d\n", table->n_philosophers);
		printf("Philosopher Last Meal is %ld", table->philosophers->last_meal);
		printf("Philosopher Started Time is %ld", table->start_time);
		printf("Current Time is %ld\n", update_current_time(table));
		usleep(1000000);
*/