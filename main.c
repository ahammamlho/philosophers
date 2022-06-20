/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:57:57 by ahammam           #+#    #+#             */
/*   Updated: 2022/06/20 16:48:42 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void init_args(t_param *param, char **args)
{
    param->start_time = get_time();
    param->philos_nbr = ft_atoi(args[1]);
    param->time_to_die = ft_atoi(args[2]);
    param->time_to_eat = ft_atoi(args[3]);
    param->time_to_sleep = ft_atoi(args[4]);
    if (args[5])
        param->meals_to_eat = ft_atoi(args[5]);
    else
        param->meals_to_eat = -1;
}

static int check_arg(int ac, char **av)
{
    int i;

    i = 1;
    if (ac != 5 && ac != 6)
        return (printf("Error: Wrong Syntax\n"), 0);
    while (av[i])
    {
        if (ft_atoi(av[i]) == -1)
            return (printf("Error: Unvalid arguments\n"), 0);
        i++;
    }
    return (1);
}

int main(int ac, char **av)
{
    t_param param;
    t_philo *philo;

    if (!check_arg(ac, av))
        return (1);
    init_args(&param, av);
    philo = create_philo(&param);
    if (philo == NULL && free_data(philo) == 0)
        return (1);
    if (param.philos_nbr == 1)
    {
        printer(philo, TAKEN_FORK);
        ft_sleep(param.time_to_die, philo);
        printer(philo, DEAD);
    }
    if (join_philo(philo, param.philos_nbr) && free_data(philo) == 0)
        return (1);
    free_data(philo);
    return 0;
}