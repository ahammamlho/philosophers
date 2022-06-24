/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:23:18 by ahammam           #+#    #+#             */
/*   Updated: 2022/06/24 16:53:40 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdbool.h>
#include <stdio.h>
#include <semaphore.h>
#include <signal.h>

#define TAKEN_FORK 1
#define EATING 2
#define SLEEPING 3
#define THINKING 4
#define DEAD 5

typedef struct s_param
{
    sem_t *print;
    sem_t *forks;
    sem_t *death;
    int philos_nbr;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int meals_to_eat;
    long start_time;
} t_param;

typedef struct s_philo
{
    int id;
    t_param *param;
    pid_t philo_p;
    long last_meal;
    int meals_eaten;
} t_philo;

int ft_atoi(const char *str);
long get_time();
void print_exit(char *msg);
void create_philo(t_param *param);
void ft_sleep(long s_time, t_philo *ph);
void printer(t_philo *philo, int state);
void actions(t_philo *philo);
#endif
