#include "philo.h"

void	init_philosophers_info(t_input *info, char **argv)
{
	info->n_philosophers = 0;
	info->n_times_p_must_eat = 0;
	info->time_to_die = 0;
	info->time_to_eat = 0;
	info->time_to_sleep = 0;
	fill_philosophers_info(info, argv);
}

void	fill_philosophers_info(t_input *info, char **argv)
{
	info->n_philosophers = atoi(argv[1]);
	info->time_to_die = atoi(argv[2]);
	info->time_to_eat = atoi(argv[3]);
	info->time_to_sleep = atoi(argv[4]);
	if (argv[5])
		info->n_times_p_must_eat = atoi(argv[5]);
	else
		info->n_times_p_must_eat = 0;
}

void	init_philosophers(t_input *info, t_philosopher *philosopher)
{
	int	i;

	i = 0;
	while (i < info->n_philosophers)
	{
		philosopher[i].index = i + 1;
		philosopher[i].meal = 0;
		philosopher[i].fork = 0;
		philosopher[i].p_info = info;
		i++;
	}
}
