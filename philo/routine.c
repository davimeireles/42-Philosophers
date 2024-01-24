#include "philo.h"

void	*dinner(void *data)
{
	t_input *table;
	table = (t_input *) data;
	printf("Total Philosophers is %d\n",table->n_philosophers);
	usleep(150);
	return (0);
}
