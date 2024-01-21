#include "philo.h"


void	*creat_threads(t_philosopher *philosopher, t_input *info)
{
	int	i;
	int	total_philosophers;

	i = 0;
	total_philosophers = info->n_philosophers;
	philosopher->thread = malloc(sizeof(pthread_t) * total_philosophers);
	if (!philosopher->thread)
		return (NULL);
	while (i < total_philosophers)
	{
		pthread_create(&philosopher->thread[i], NULL, &routine, &philosopher[i]);
		i++;
	}
	return (NULL);
}

void	*join_threads(t_philosopher *philosopher, t_input *info)
{
	int	i;
	int	total_philosophers;

	i = 0;
	total_philosophers = info->n_philosophers;
	while (i < total_philosophers)
	{
		pthread_join(philosopher->thread[i], 0);
		i++;
	}
	return (NULL);
}

void	*threads(t_philosopher *philosopher, t_input *info)
{
	creat_threads(philosopher, info);
	join_threads(philosopher, info);
	printf("Meals = %d\n",philosopher->meal);
	return (NULL);
}

