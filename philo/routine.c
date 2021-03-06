/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:36:14 by ahammam           #+#    #+#             */
/*   Updated: 2022/06/25 13:27:03 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	thinking(t_philo *philo)
{
	if (*(philo->alive) == true)
		printer(philo, THINKING);
	if (philo->meals_eaten == 0)
	{
		if (ft_sleep(100, philo))
			return (1);
	}
	return (0);
}

static int	eating(t_philo *ph)
{
	pthread_mutex_lock(ph->left_fork);
	if (*(ph->alive) == true)
		printer(ph, TAKEN_FORK);
	pthread_mutex_lock(ph->rt_f);
	if (*(ph->alive) == true)
		printer(ph, TAKEN_FORK);
	if (*(ph->alive) == true)
		printer(ph, EATING);
	ph->last_meal = get_time() - ph->param->start_time;
	if (ft_sleep(ph->param->time_to_eat, ph))
	{
		pthread_mutex_unlock(ph->rt_f);
		pthread_mutex_unlock(ph->left_fork);
		return (1);
	}
	pthread_mutex_unlock(ph->rt_f);
	pthread_mutex_unlock(ph->left_fork);
	ph->meals_eaten++;
	return (0);
}

static int	sleeping(t_philo *ph)
{
	if (*(ph->alive) == true)
		printer(ph, SLEEPING);
	if (ft_sleep(ph->param->time_to_sleep, ph))
		return (1);
	return (0);
}

void	*actions(void *ph)
{
	t_philo		*philo;

	philo = (t_philo *)ph;
	if (philo == NULL || philo->param->philos_nbr == 1)
		return (NULL);
	if (philo->id % 2 == 1)
		thinking(philo);
	while (1)
	{
		if (eating(philo))
			break ;
		if (philo->meals_eaten == philo->param->meals_to_eat)
			break ;
		if (sleeping(philo))
			break ;
		if (thinking(philo))
			break ;
	}
	return (NULL);
}
