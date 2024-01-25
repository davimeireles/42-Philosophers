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
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
	t_table			*table;
}	t_philosopher;

typedef struct s_input_info
{
	int				total_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				n_times_philo_must_eat;
	bool			finish;
	long 			start_time;
	long 			current_time;
	pthread_mutex_t access;
}	t_table;

/* Main */
int		main(int argc, char **argv);

/* Validate Input */
void	p_error(t_error error);
bool	check_num_args(int argc);
bool	is_digit(char **argv);
bool	check_atoi(char **argv);
void	check_input(int argc, char **argv);

/* Utils */
int		ft_atoi(char *str);
long	ft_atol(char *str);
long	get_long(t_philosopher *philo, long *data);
bool	get_mutex_bool(t_philosopher *philo, bool *data);

/* Philosopher Utils */
void	init_table(t_table *table, char **argv);
void	init_philosophers(t_philosopher *philo, t_table *table);

/* Routine */
void	*dinner(void *data);
void	to_eat(t_philosopher *philo);
void	to_think(t_philosopher *philo);
void	to_sleep(t_philosopher *philo);

/* Threads Utils */
void	creat_threads(t_philosopher *philo);
void	join_threads(t_philosopher *philo);
void	threads(t_philosopher *philo);

/* Mutex Utils */


/* Date Utils */
long	get_time(void);
long	update_current_time(t_table *table);

/* Free Memory */
//void	free_struct_philosophers(t_table *table);


#endif
