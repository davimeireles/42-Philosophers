/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:11:44 by dmeirele          #+#    #+#             */
/*   Updated: 2024/01/23 21:11:44 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

long	update_current_time(t_table *table)
{
	long	ret;

	pthread_mutex_lock(&table->access);
	ret = get_time() - table->start_time;
	pthread_mutex_unlock(&table->access);

	return (ret);
}
