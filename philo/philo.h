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
typedef struct s_fork	t_fork;

typedef enum operation
{
	INIT,
	DESTROY,
	LOCK,
	UNLOCK,
}	t_operation;

typedef enum s_error
{
	N_ARGS,
	INVALID_PARAMETER,
	RANGE_OR_NEGATIVE,
	MALLOC_ERROR,
}	t_error;

typedef struct s_philosopher
{
	int				index;
	long 			meals;
	long 			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	dead;
	t_table			*p_info;
}	t_philosopher;

typedef struct s_input_info
{
	int				n_philosophers;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				n_times_philo_must_eat;
	bool			all_ate;
	int				dead;
	long 			s_time;
	t_philosopher	*philosophers;
	pthread_mutex_t mutex;
	pthread_mutex_t print;
	pthread_mutex_t *forks;
	pthread_mutex_t checker;
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
void	op_handle(pthread_mutex_t *mutex, t_operation op);

/* Philosopher Utils */
void	init_philosophers_info(t_table *info, char **argv);
void	fill_philosophers_info(t_table *info, char **argv);
void	assign_forks(t_philosopher *philosopher, t_fork *forks, int pos);
void	init_philosophers(t_table *info);

/* Routine */
void	*dinner(void *data);

/* Threads Utils */
void	creat_threads(t_philosopher *philosopher, t_table *info);
void	join_threads(t_philosopher *philosopher, t_table *info);
void	threads(t_philosopher *philosopher, t_table *info);

/* Mutex Utils */
void	init_mutex(t_philosopher *philosopher, t_table info);
void	destroy_mutex(t_philosopher *philosopher, t_table info);

/* Date Utils */
int		get_time_in_ms(t_timeval *time1, t_timeval *time2);
long	get_time(void);
int		ft_abs(int number);
void	update_time(t_timeval *src, t_timeval *dest);

/* Free Memory */
void	free_struct_philosophers(t_philosopher *philosopher);


#endif
