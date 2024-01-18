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

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

void *routine()
{
	printf("Thread\n");
	sleep(2);
	printf("Finish\n");
	return NULL;
}

int main()
{
	pthread_t t1;
	pthread_t t2;

	pthread_create(&t1, NULL, routine, NULL);
	pthread_create(&t2, NULL, routine, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}