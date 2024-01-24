#include "philo.h"

void	fill_philosophers(t_table *info, char **argv)
{
	info->n_philosophers = atoi(argv[1]);
	info->time_to_die = atol(argv[2]) * 1000;
	info->time_to_eat = atol(argv[3]) * 1000;
	info->time_to_sleep = atol(argv[4]) * 1000;
	if (argv[5])
		info->n_times_philo_must_eat = atoi(argv[5]);
	else
		info->n_times_philo_must_eat = -1;
	info->all_ate = 0;
	info->dead = 0;
	info->s_time = get_time();
	pthread_mutex_init(&info->mutex, 0);
	pthread_mutex_init(&info->print, 0);
	while (i < info->n_philosophers)
	{
		op_handle(&info->forks[i].fork, INIT);
		info->forks[i].id_fork = i + 1;
		i++;
	}
	init_philosophers(info);
}

void	assign_forks(t_philosopher *philosopher, t_fork *forks, int pos)
{
	int	ph_number;

	ph_number = philosopher->p_info->n_philosophers;
	if (philosopher->index % 2 == 0)
	{
		philosopher->r_fork = &forks[pos];
		philosopher->l_fork = &forks[(pos + 1) % ph_number];
	}
	else
	{
		philosopher->l_fork = &forks[pos];
		philosopher->r_fork = &forks[(pos + 1) % ph_number];
	}
}

void	init_philosophers(t_input *info)
{
	int				i;
	t_philosopher	*philosopher;

	i = 0;
	while (i < info->n_philosophers)
	{
		philosopher[i].index = i + 1;
		philosopher->meals = 0;
		philosopher->ph_full = false;
		philosopher->p_info = info;
		philosopher = info->philosophers;
		assign_forks(philosopher, info->forks, i);
		i++;
	}
}
