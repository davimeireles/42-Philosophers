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

int	get_time_in_ms(t_timeval *time1, t_timeval *time2)
{
	int	seconds;
	int	u_seconds;

	seconds = (time1->tv_sec - time2->tv_sec) * 1000;
	u_seconds = (time1->tv_usec - time2->tv_usec) / 1000;
	return (ft_abs(seconds + u_seconds));
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

int	ft_abs(int number)
{
	if (number < 0)
		number = number * -1;
	return (number);
}

void	update_time(t_timeval *src, t_timeval *dest)
{
	dest->tv_sec = src->tv_sec;
	dest->tv_usec = src->tv_usec;
}
