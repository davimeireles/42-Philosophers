#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

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
//	pthread_t	thread;
	t_input		*p_info;
	int			index;
	int			eat;
	int			think;
	int			sleep;
	int			fork;
}	t_philosopher;

/* main */
int		main(int argc, char **argv);

/* validate input */
void	p_error(t_error error);
bool	check_num_args(int argc);
bool	is_digit(char **argv);
bool	check_atoi(char **argv);
void	check_input(int argc, char **argv);

/* Philosopher Utils */
void	init_philosophers_info(t_input *info, char **argv);
void	fill_philosophers_info(t_input *info, char **argv);
void	init_philosophers(t_input *info, t_philosopher *philosopher);

/* utils */
int		ft_atoi(char *str);
long	ft_atol(char *str);

#endif