/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:52:30 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/16 23:35:56 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** This function initiates struct s_control (t_ctrl). It parses the user's input
** into the struct. It then calls the init_mutex() function to allocate the
** necessary space for all the mutexes and initialize each accordingly; and then
** allocates the necessary space for the threads list - 'control->threads
** (pthread_t *)' without initializing the threads.
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
	if (!control->nu_of_philo || control->nu_of_philo > 200)
		error_message(WRONG_PHILO_NU);
	control->time_to_die = (t_time)ft_atoi(argv[i++]);
	control->time_to_eat = (t_time)ft_atoi(argv[i++]);
	control->time_to_sleep = (t_time)ft_atoi(argv[i++]);
	if (argc != i)
		control->nu_meals = (t_time)ft_atoi(argv[i]);
	else
		control->nu_meals = -1;
	control->deaths = FALSE;
	init_forks(control);
	init_mutex(control);
	control->start_time = get_current_time();
	return (control);
}
