/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:22:16 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/25 13:41:20 by mlanca-c         ###   ########.fr       */
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
**
** @return
** 		- the init_philo() function returns a philo - struct s_fork - variable
** 		to the variable 'controllers'.
*/
t_philo	*init_philo(t_ctrl *controllers)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)ft_malloc(sizeof(t_philo) * controllers->nu_philo,
			error_message);
	i = 0;
	while (i < controllers->nu_philo)
	{
		philo[i].id = i + 1;
		philo[i].color = get_color(i);
		philo[i].last_action = controllers->start_time;
		philo[i].last_meal = controllers->start_time;
		philo[i].nu_meal = 0;
		philo[i].has_forks = false;
		philo[i].controllers = controllers;
		i++;
	}
	return (philo);
}
