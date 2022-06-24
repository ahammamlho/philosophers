/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:45:09 by ahammam           #+#    #+#             */
/*   Updated: 2022/06/24 16:45:54 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void print_exit(char *msg)
{
    printf("%s \n", msg);
    exit(EXIT_FAILURE);
}

void ft_sleep(long s_time, t_philo *ph)
{
    long sleep_start;
    long current_time;

    sleep_start = get_time();
    current_time = sleep_start;
    while (sleep_start + s_time > current_time)
    {
        if (ph->param->time_to_die < (current_time - ph->param->start_time - ph->last_meal))
        {
            sem_wait(ph->param->death);
            printer(ph, DEAD);
            sem_close(ph->param->print);
            sem_close(ph->param->forks);
            sem_close(ph->param->death);
            sem_unlink("forks_s");
            sem_unlink("print_s");
            sem_unlink("death_s");
            exit(EXIT_FAILURE);
        }
        usleep(150);
        current_time = get_time();
    }
}