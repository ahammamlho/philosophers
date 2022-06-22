#ifndef PHILO_H
#define PHILO_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>

#define TAKEN_FORK 1
#define EATING 2
#define SLEEPING 3
#define THINKING 4
#define DEAD 5

typedef struct s_param
{
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
    pthread_mutex_t *right_fork;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *print;
    // pthread_mutex_t *death;
    pthread_t philo_p;
    long last_meal;
    int meals_eaten;
    bool *alive;
} t_philo;

int ft_atoi(const char *str);
long get_time();
t_philo *create_philo(t_param *param);
void *actions(void *ph);
void printer(t_philo *ph, int state);
int free_data(t_philo *ph);
int join_philo(t_philo *philo, int ph);
int ft_sleep(long s_time, t_philo *ph);
#endif
