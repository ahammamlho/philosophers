/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:42:43 by ahammam           #+#    #+#             */
/*   Updated: 2022/06/24 16:47:53 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void printer(t_philo *philo, int state)
{
    sem_wait(philo->param->print);
    printf("%ld\t%d", get_time() - philo->param->start_time, philo->id);
    if (state == TAKEN_FORK)
        printf("\thas taken a fork\n");
    else if (state == EATING)
        printf("\tis eating\n");
    else if (state == SLEEPING)
        printf("\tis sleeping\n");
    else if (state == THINKING)
        printf("\tis thinking\n");
    else if (state == DEAD)
        printf("\tdied\n");
    if (state == DEAD)
        exit(EXIT_FAILURE);
    sem_post(philo->param->print);
}

void sleeping(t_philo *philo)
{
    printer(philo, SLEEPING);
    ft_sleep(philo->param->time_to_sleep, philo);
}

static void eating(t_philo *philo)
{
    sem_wait(philo->param->forks);
    printer(philo, TAKEN_FORK);
    sem_wait(philo->param->forks);
    printer(philo, TAKEN_FORK);
    printer(philo, EATING);
    philo->last_meal = get_time() - philo->param->start_time;
    ft_sleep(philo->param->time_to_eat, philo);
    philo->meals_eaten++;
    sem_post(philo->param->forks);
    sem_post(philo->param->forks);
}

void thinking(t_philo *philo)
{
    printer(philo, THINKING);
    if (philo->meals_eaten == 0)
        ft_sleep(100, philo);
}

void actions(t_philo *philo)
{
    if (philo->param->philos_nbr == 1)
    {
        printer(philo, TAKEN_FORK);
        ft_sleep(philo->param->time_to_die, philo);
        printer(philo, DEAD);
        exit(EXIT_SUCCESS);
    }
    if (philo->id % 2 == 0)
        thinking(philo);
    while (1)
    {
        eating(philo);
        if (philo->meals_eaten == philo->param->meals_to_eat)
            break;
        sleeping(philo);
        thinking(philo);
        usleep(100);
    }
    exit(EXIT_SUCCESS);
}
