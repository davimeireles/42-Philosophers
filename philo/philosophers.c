#include "philo.h"

void	*routine(void *data)
{
	t_philosopher *philosopher;
	philosopher = (t_philosopher *) data;
	for(int i = 0; i < 10000; i++) {
		philosopher->meal++;
	}
	return (0);
}
