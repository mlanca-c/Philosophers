/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 22:31:51 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/17 00:21:42 by mlanca-c         ###   ########.fr       */
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
	static t_color	color[14] = {ANSI_RED, ANSI_GREEN, ANSI_YELLOW, ANSI_BLUE,
		ANSI_MAGENTA, ANSI_CYAN, ANSI_WHITE, ANSI_BRED, ANSI_BGREEN,
		ANSI_BYELLOW, ANSI_BBLUE, ANSI_BMAGENTA, ANSI_BCYAN, ANSI_BWHITE};

	return (color[id % 14]);
}

/*
** This function's while loop allocates the necessary memory space for a struct
** s_philosopher - t_philo type. Then sets all its attributes to default.
** 	- id: it's set to the index of the philosophers - 1 in the 'control' list.
** 	- color: it's set to a certain color depending on the philos id using the
** 			get_philos_color() function.
** 	- status: it's set to the enum THINKING.
** 	- last_ate: it's set to -1, cause the philosopher hasn't eaten yet.
** 	- times_philo_ate: it's set to 0.
** 	- is_dead: it's set to FALSE.
** Then calls the init_thread() function to create the threads that will go to.
** the simulation() function with the philosopher - t_philo - as its parameter.
** 
** @param	t_ctrl	*control	- main variable of the program. It contains the
** 								threads list, not initialized but allocated.
*/
void	init_philosophers(t_ctrl *control)
{
	int		i;

	i = control->nu_of_philo;
	control->philos = (t_philo *)ft_malloc(sizeof(t_philo) * i, error_message);
	i = 0;
	while (i < control->nu_of_philo)
	{
		control->philos[i].id = i + 1;
		control->philos[i].color = get_color(i);
		control->philos[i].last_meal = control->start_time;
		control->philos[i].last_action = control->start_time;
		control->philos[i].meal_times = 0;
		control->philos[i].control = control;
		i++;
	}
	init_thread(control);
}

/*
*/
void	init_philosopher(t_ctrl *control)
{
	control->philos = (t_philo *)ft_malloc(sizeof(t_philo), error_message);
	control->philos->id = 1;
	control->philos->color = get_color(1);
	control->philos->last_meal = control->start_time;
	control->philos->last_action = control->start_time;
	control->philos->meal_times = 0;
	control->philos->control = control;
	control->threads = (pthread_t *)ft_malloc(sizeof(pthread_t), error_message);
	if (pthread_create(control->threads, NULL, &simulation_one_philosopher,
			(void *)control->philos))
		exit_program(control, ERROR_THREAD);
}
