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

void	philo_free(t_table *table)
{
	free(table->philo);
	free(table->forks);
}

int	main(int argc, char **argv)
{
	t_table table;

	check_input(argc, argv);
	init_table(&table, argv);
	init_threads(&table);
	join_threads(&table);
	philo_free(&table);
}
