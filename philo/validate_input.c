/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:26:38 by dmeirele          #+#    #+#             */
/*   Updated: 2024/01/29 15:37:11 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_error(t_error error)
{
	if (error == N_ARGS)
		printf("Invalid number of arguments.\n");
	if (error == INVALID_PARAMETER)
		printf("Invalid parameter, only numbers accepted.\n");
	if (error == RANGE_OR_NEGATIVE)
		printf("Number out of the MAX_INT range or its neg/null.\n");
	exit(EXIT_FAILURE);
}

bool	check_num_args(int argc)
{
	if (argc == 5 || argc == 6)
		return (true);
	return (false);
}

bool	is_digit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == '-'
					|| argv[i][j] == '+'))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_atoi(char **argv)
{
	int		i;
	int		nbr;
	long	l_nbr;

	i = 1;
	while (argv[i])
	{
		nbr = ft_atoi(argv[i]);
		l_nbr = ft_atol(argv[i]);
		if (nbr != l_nbr || nbr < 1)
			return (false);
		i++;
	}
	return (true);
}

void	check_input(int argc, char **argv)
{
	if (!(check_num_args(argc)))
		p_error(N_ARGS);
	if (!(is_digit(argv)))
		p_error(INVALID_PARAMETER);
	if (!(check_atoi(argv)))
		p_error(RANGE_OR_NEGATIVE);
}
