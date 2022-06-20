/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:45:09 by ahammam           #+#    #+#             */
/*   Updated: 2022/06/20 16:37:27 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_atoi(const char *str)
{
    int i;
    long int result;

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

long get_time()
{
    struct timeval tp;

    gettimeofday(&tp, NULL);
    return (tp.tv_sec * 1000 + tp.tv_usec / 1000);
}

int free_data(t_philo *ph)
{
    int i;
    int philo;

    i = 0;
    philo = ph[0].param->philos_nbr;
    while (i < philo)
    {
        if (ph[i].right_fork != NULL)
            free(ph[i].right_fork);
        i++;
    }
    if (ph->alive != NULL)
        free(ph->alive);
    if (ph->print != NULL)
        free(ph->print);
    if (ph->death != NULL)
        free(ph->death);
    if (ph != NULL)
        free(ph);
    return (0);
}

int ft_sleep(long s_time, t_philo *ph)
{
    long sleep_start;
    long current_time;

    sleep_start = get_time();
    current_time = sleep_start;
    while (sleep_start + s_time > current_time)
    {
        if (*(ph->alive) == false)
            return (1);
        if (ph->param->time_to_die < ((current_time - ph->param->start_time) - ph->last_meal))
        {
            pthread_mutex_lock(ph->death);
            printer(ph, DEAD);
            *(ph->alive) = false;
            pthread_mutex_unlock(ph->death);
            return (1);
        }
        usleep(150);
        current_time = get_time();
    }
    return (0);
}