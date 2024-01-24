#include "philo.h"

void	creat_threads(t_philosopher *philosopher, t_input *info)
{
	int	i;
	int	total_philosophers;

	i = 0;
	total_philosophers = info->n_philosophers;
	philosopher->thread = malloc(sizeof(pthread_t) * total_philosophers);
	if (!philosopher->thread)
		return ;
	while (i < total_philosophers)
	{
		pthread_create(philosopher->thread, NULL, &dinner, &philosopher[i]);
		i++;
	}
}

void	join_threads(t_philosopher *philosopher, t_input *info)
{
	int	i;
	int	total_philosophers;

	i = 0;
	total_philosophers = info->n_philosophers;
	while (i < total_philosophers)
	{
		pthread_join(philosopherthread, 0);
		i++;
	}
}

void	threads(t_philosopher *philosopher, t_input *info)
{
	creat_threads(philosopher, info);
//	join_threads(philosopher, info);
}

