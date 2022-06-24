/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:22:57 by ahammam           #+#    #+#             */
/*   Updated: 2022/06/24 16:39:50 by ahammam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
        return (print_exit("Error: Wrong Syntax"), 0);
    while (av[i])
    {
        if (ft_atoi(av[i]) == -1)
            return (print_exit("Error: Unvalid arguments"), 0);
        i++;
    }
    return (1);
}

int main(int ac, char **av)
{
    t_param param;

    if (!check_arg(ac, av))
        return (1);
    init_args(&param, av);
    create_philo(&param);

    return 0;
}