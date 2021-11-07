/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:52:30 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/07 13:40:45 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** This function initiates struct s_control (t_ctrl). It parses the user's input
** into the struct. It then calls the init_forks() function to allocate the
** necessary space for all the forks and initialize each accordingly; and then
** does the same for the philosophersi by calling the init_philosophers()
** function.
**
** @param	int		argc	- argument counter.
** @param	char	*argv	- command line input provided by the user.
**
** @returns
** 	The init_control() function returns a pointer to the struct t_ctrl, already
** 	initiated, if successful. In case of error the error_message() function is
** 	called and the program exits with EXIT_FAILURE.
*/
t_ctrl	*init_control(int argc, char **argv)
{
	t_ctrl	*control;
	int		i;

	control = (t_ctrl *)ft_malloc(sizeof(t_ctrl), error_message);
	i = 1;
	control->nu_of_philo = ft_atoi(argv[i++]);
	control->time_to_die = ft_atoi(argv[i++]);
	control->time_to_eat = ft_atoi(argv[i++]);
	control->time_to_sleep = ft_atoi(argv[i++]);
	if (argc != i)
		control->nu_of_time_to_eat = ft_atoi(argv[i]);
	else
		control->nu_of_time_to_eat = -1;
	control->forks = init_forks(control->nu_of_philo);
	//control->philosophers = init_philosophers(control);
	return (control);
}
