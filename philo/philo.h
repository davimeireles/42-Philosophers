/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:58:54 by dmeirele          #+#    #+#             */
/*   Updated: 2024/01/29 14:53:09 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/time.h>

typedef struct timeval t_timeval;
typedef struct s_input_info t_table;
typedef struct s_philosopher t_philosopher;

typedef enum s_error
{
	N_ARGS,
	INVALID_PARAMETER,
	RANGE_OR_NEGATIVE,
	MALLOC_ERROR,
}	t_error;

typedef struct s_philosopher
{
	int				id;
	long 			meals;
	long 			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t death;
	t_table			*table;
}	t_philosopher;

typedef struct s_input_info
{
	int				total_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			minimum_meals;
	long 			all_full;
	int 			dead;
	long 			start_time;
	t_philosopher	*philo;
	pthread_mutex_t mutex;
	pthread_mutex_t print;
	pthread_mutex_t *forks;
	pthread_t 		checker;
}	t_table;

/* Main */
int		main(int argc, char **argv);
void	philo_free(t_table *table);

/* Validate Input */
void	p_error(t_error error);
bool	check_num_args(int argc);
bool	is_digit(char **argv);
bool	check_atoi(char **argv);
void	check_input(int argc, char **argv);

/* Utils */
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
int		print_status(t_philosopher *philo, char *status);

/* Philosopher Utils */
void			init_table(t_table *table, char **argv);
t_philosopher	*init_philosophers(t_table *table);
pthread_mutex_t *init_forks(int total_philos);

/* Routine */
void	*dinner(void *data);
int		grab_forks(t_philosopher *philo);
int		go_eat(t_philosopher *philo);
int		go_sleep(t_philosopher *philo);
int		go_think(t_philosopher *philo);

/* Threads Utils */
void	init_threads(t_table *table);
void	join_threads(t_table *table);
void	*check_status(void *data);
int		check_if_dead(t_table *table);
int		check_if_ate(t_table *table);

/* Date Utils */
long		get_time(void);
long		current_time(long time);
long int	get_time2(void);
void		ft_usleep(long int miliseconds);

#endif
