/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:45:09 by ahammam           #+#    #+#             */
/*   Updated: 2022/06/25 13:27:03 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int			i;
	long int	result;

	i = 0;
	result = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (result > 2147483647 || str[i] != 0 || result == 0)
		return (-1);
	return ((int)(result));
}

long	get_time(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return (tp.tv_sec * 1000 + tp.tv_usec / 1000);
}

int	free_data(t_philo *ph)
{
	int	i;
	int	philo_nbr;

	i = 0;
	philo_nbr = ph[0].param->philos_nbr;
	while (i < philo_nbr)
	{
		if (ph[i].rt_f != NULL)
			free(ph[i].rt_f);
		i++;
	}
	if (ph->alive != NULL)
		free(ph->alive);
	if (ph->print != NULL)
		free(ph->print);
	if (ph != NULL)
		free(ph);
	return (0);
}

int	ft_sleep(long s_time, t_philo *ph)
{
	long	sleep_start;
	long	current_time;

	sleep_start = get_time();
	current_time = sleep_start;
	while (sleep_start + s_time > current_time)
	{
		if (*(ph->alive) == false)
			return (1);
		if (ph->param->time_to_die < ((current_time - ph->param->start_time) \
					- ph->last_meal))
		{
			printer(ph, DEAD);
			return (1);
		}
		usleep(150);
		current_time = get_time();
	}
	return (0);
}
