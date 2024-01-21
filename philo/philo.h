#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/time.h>

typedef enum s_error
{
	N_ARGS,
	INVALID_PARAMETER,
	RANGE_OR_NEGATIVE
}	t_error;

typedef struct s_input_info
{
	int	n_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	n_times_p_must_eat;
}	t_input;

typedef struct s_philosopher
{
	pthread_t		*thread;
	pthread_mutex_t	*mutex;
	t_input			*p_info;
	int				index;
	int				meal;
	int				fork;
}	t_philosopher;

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

/* Philosopher Utils */
void	init_philosophers_info(t_input *info, char **argv);
void	fill_philosophers_info(t_input *info, char **argv);
void	init_philosophers(t_input *info, t_philosopher *philosopher);

/* Philosophers */
void	*routine();

/* Threads Utils */
void	*creat_threads(t_philosopher *philosopher, t_input *info);
void	*join_threads(t_philosopher *philosopher, t_input *info);
void	*threads(t_philosopher *philosopher, t_input *info);

/* Mutex Utils */
void	*init_mutex(t_philosopher *philosopher, t_input *info);
void	*unlock_mutex(t_philosopher *philosopher, t_input *info);

/* Date Utils */
void	time_execution();

/* Free Memory */
void	free_struct_philosophers(t_philosopher *philosopher);

#endif
