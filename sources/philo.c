/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:50:57 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/26 22:01:08 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** This function assigns a color to a philosopher based on it's 'id'.
**
** @param	int	id	- id of the philosopher. Its the number identification that
** 					will define the color that will be assign to the
** 					philosopher.
** @return
** 		- The get_philos_color() function returns the philosophers color.
*/
t_color	get_color(int id)
{
	static t_color	color[14] = {RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE,
		BRED, BGREEN, BYELLOW, BBLUE, BMAGENTA, BCYAN, BWHITE};

	return (color[id % 14]);
}

/*
** This function initializes the 'philo' - struct s_philo - variable in 
** 'controllers'.
** It allocates the necessary memory space for the variable and it sets all
** variables to default.
**
** @param	t_ctrl	*controllers	- main variable of the program.
** @param	t_error	*error	- variable address of an error - typedef char *.
** 							In case of error, this variable will stop being null
** 							and the function will end. The exit_program()
** 							function will then be called and 'error' will be
** 							displayed in the command line.
**
** @return
** 		- the init_philo() function returns a philo - struct s_fork - variable
** 		to the variable 'controllers'.
*/
t_philo	*init_philo(t_ctrl *controllers, t_error *error)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)ft_malloc(sizeof(t_philo) * controllers->nu_philo,
			error, MALLOC_PHILO);
	if (*error)
		return (philo);
	i = 0;
	while (i < controllers->nu_philo)
	{
		philo[i].id = i + 1;
		philo[i].color = get_color(i);
		philo[i].last_action = controllers->start_time;
		philo[i].last_meal = controllers->start_time;
		philo[i].nu_meal = 0;
		philo[i].fork = false;
		philo[i].controllers = controllers;
		i++;
	}
	return (philo);
}
