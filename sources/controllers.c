/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controllers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:55:25 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/25 13:54:36 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** This function initializes the main variable of the program - struct
** s_controllers 'controllers'.
**
** @line 38			It allocates the necessary space for the variable
** 					controllers using the ft_malloc() function.
** @line 40, 51		Parses the user's input given by the command line arguments.
** @line 52, 56		Initializes other struct variables inside controllers -
** 					fork, philo, thread, mutex_print - and sets the non-struct
**					variables to their default values.
**
** @param	int		argc	- argument counter.
** @param	char	*argv	- command line arguments.
**
** @return
** 		- The init_controllers() function returns the struct s_controllers
** 		variable already initialized to the main() function.
*/
t_ctrl	*init_controllers(int argc, char *argv[])
{
	int		i;
	t_ctrl	*controllers;

	controllers = (t_ctrl *)ft_malloc(sizeof(t_ctrl), error_message);
	i = 1;
	controllers->nu_philo = ft_atoi(argv[i++]);
	if (controllers->nu_philo == 0)
		error_message(NO_PHILO);
	if (controllers->nu_philo > 200)
		error_message(TOO_MANY_PHILO);
	controllers->time_to_die = ft_atoi(argv[i++]);
	controllers->time_to_eat = ft_atoi(argv[i++]);
	controllers->time_to_sleep = ft_atoi(argv[i++]);
	if (argc != i)
		controllers->max_meal = ft_atoi(argv[i]);
	else
		controllers->max_meal = 0;
	if (pthread_mutex_init(&(controllers->mutex_print), NULL))
		exit_program(controllers, EXIT_MUTEX);
	controllers->fork = init_fork(controllers);
	controllers->start_time = get_current_time();
	controllers->philo = init_philo(controllers);
	return (controllers);
}
