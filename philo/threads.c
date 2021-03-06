/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:11:01 by ahammam           #+#    #+#             */
/*   Updated: 2022/06/25 13:28:12 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	fill_philo(t_philo *philo, t_param *par)
{
	int	i;

	i = 0;
	while (i < par->philos_nbr)
	{
		philo[i].rt_f = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (!philo[i].rt_f || pthread_mutex_init(philo[i].rt_f, NULL))
			return (1);
		i++;
	}
	i = 0;
	while (i < par->philos_nbr)
	{
		philo[i].id = i + 1;
		philo[i].left_fork = philo[(i + 1) % par->philos_nbr].rt_f;
		philo[i].alive = philo[0].alive;
		philo[i].print = philo[0].print;
		philo[i].param = par;
		philo[i].last_meal = 0;
		philo[i].meals_eaten = 0;
		if (pthread_create(&philo[i].philo_p, 0, &actions, (void *)&philo[i]))
			return (1);
		i++;
	}
	return (0);
}

t_philo	*create_philo(t_param *param)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * param->philos_nbr);
	philo->alive = (bool *)malloc(sizeof(bool));
	philo->print = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!philo || !philo->alive || !philo->print)
		return (NULL);
	*(philo->alive) = true;
	if (pthread_mutex_init(philo->print, NULL))
		return (NULL);
	if (fill_philo(philo, param))
		return (NULL);
	return (philo);
}

int	join_philo(t_philo *philo, int ph)
{
	int	i;

	i = 0;
	while (i < ph)
	{
		if (pthread_join(philo[i].philo_p, NULL))
			return (1);
		pthread_mutex_destroy(philo[i].rt_f);
		i++;
	}
	pthread_mutex_destroy(philo->print);
	return (0);
}

void	printer(t_philo *ph, int state)
{
	pthread_mutex_lock(ph->print);
	if (*(ph->alive) == true)
	{
		printf("%ld\t", get_time() - ph->param->start_time);
		printf("%d\t", ph->id);
		if (state == TAKEN_FORK)
			printf("has taken a fork\n");
		else if (state == EATING)
			printf("is eating\n");
		else if (state == SLEEPING)
			printf("is sleeping\n");
		else if (state == THINKING)
			printf("is thinking\n");
		else if (state == DEAD)
		{
			printf("died\n");
			*(ph->alive) = false;
		}
	}
	pthread_mutex_unlock(ph->print);
}
