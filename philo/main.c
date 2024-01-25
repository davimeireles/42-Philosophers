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
	t_table table;
	t_philosopher *philo;

	check_input(argc, argv);
	init_table(&table, argv);
/*	printf("Total Philosophers is %d\nTime to Die is %ld\nTime to Eat is %ld\n"
		   "Time to Sleep is %ld\nEach Philosopher Must Eat %d Times\n"
		   "Start Time is %ld\nCurrent Time is %ld\n",table.total_philos,table.time_to_die,table.time_to_eat,
		   table.time_to_sleep,table.n_times_philo_must_eat,table.start_time,table.current_time);*/
	philo = malloc(sizeof(t_philosopher) * table.total_philos);
	if (!philo)
		return (0);
	init_philosophers(philo, &table);
	threads(philo);
}
