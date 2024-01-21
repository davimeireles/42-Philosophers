/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:12:42 by dmeirele          #+#    #+#             */
/*   Updated: 2024/01/17 23:18:44 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_input	info;
	t_philosopher *philosopher;

	check_input(argc, argv);
	init_philosophers_info(&info, argv);
	philosopher = malloc(sizeof(t_philosopher) * info.n_philosophers);
	if (!philosopher)
		return (0);
	init_philosophers(&info, philosopher);
	threads(philosopher, &info);
//	time_execution();
//	int i = 0;
/*	while (i < info.n_philosophers)
	{
		printf("Index Philosopher = %d\nNumber of philosophers = %d\nTime to die = %d\nTime to eat = %d"
			   "\nTime to sleep = %d\nNumber of times each philosophers must eat = %d\n"
			   "",philosopher[i].index,philosopher[i].p_info->n_philosophers,philosopher[i].p_info->time_to_die,
			   philosopher[i].p_info->time_to_eat,philosopher[i].p_info->time_to_sleep,
			   philosopher[i].p_info->n_times_p_must_eat);
		i++;
	}*/
	free_struct_philosophers(philosopher);
}
