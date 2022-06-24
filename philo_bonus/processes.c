/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:36:50 by ahammam           #+#    #+#             */
/*   Updated: 2022/06/24 16:55:46 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void fill_philo(t_param *param, int i, pid_t pid, int status)
{
    t_philo philo;

    while (i < param->philos_nbr)
    {
        philo.param = param;
        philo.meals_eaten = 0;
        philo.id = i + 1;
        philo.last_meal = 0;
        philo.philo_p = fork(); 
        if (philo.philo_p == -1)
            exit(EXIT_FAILURE);
        if (philo.philo_p == 0)
            actions(&philo);
        i++;
    }
    pid = waitpid(-1, &status, WEXITSTATUS(status));
    while (pid > 0)
    {
        if (status == 256)
            kill(0, SIGKILL);
        pid = waitpid(-1, &status, WEXITSTATUS(status));
    }
}

void create_philo(t_param *param)
{
    sem_unlink("forks_s");
    sem_unlink("death_s");
    sem_unlink("print_s");
    param->forks = sem_open("forks_s", O_CREAT, 0660, param->philos_nbr);
    param->print = sem_open("print_s", O_CREAT, 0660, 1);
    param->death = sem_open("death_s", O_CREAT, 0660, 1);
    if (param->forks == NULL || param->print == NULL || param->death == NULL)
        print_exit("Allocation Error");
    fill_philo(param, 0, 0, 0);
    if (sem_close(param->print) || sem_close(param->forks) || sem_close(param->death))
        print_exit("Allocation Error");
    if (sem_unlink("forks_s") || sem_unlink("print_s") || sem_unlink("death_s"))
        print_exit("Allocation Error");
}
