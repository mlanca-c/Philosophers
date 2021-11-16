/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 22:31:51 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/16 10:14:47 by mlanca-c         ###   ########.fr       */
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
char	*get_color(void)
{
	if (get_current_time() + 1 % 12 == 0)
		return (ANSI_RED);
	if (get_current_time() + 2 % 12 == 1)
		return (ANSI_BRED);
	if (get_current_time() + 3 % 12 == 2)
		return (ANSI_GREEN);
	if (get_current_time() + 4 % 12 == 3)
		return (ANSI_BGREEN);
	if (get_current_time() + 5 % 12 == 4)
		return (ANSI_YELLOW);
	if (get_current_time() + 6 % 12 == 5)
		return (ANSI_BYELLOW);
	if (get_current_time() + 7 % 12 == 6)
		return (ANSI_BLUE);
	if (get_current_time() + 8 % 12 == 7)
		return (ANSI_BBLUE);
	if (get_current_time() + 9 % 12 == 8)
		return (ANSI_MAGENTA);
	if (get_current_time() + 10 % 12 == 9)
		return (ANSI_BMAGENTA);
	if (get_current_time() + 11 % 12 == 10)
		return (ANSI_CYAN);
	if (get_current_time() + 12 % 12 == 11)
		return (ANSI_CYAN);
	return(ANSI_BWHITE);
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
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < control->nu_of_philo)
	{
		philo = (t_philo *)ft_malloc(sizeof(t_philo), error_message);
		philo->id = i + 1;
		philo->color = get_color();
		philo->last_meal = control->start_time;
		philo->last_action = control->start_time;
		philo->meal_times = 0;
		philo->control = control;
		init_thread(control, philo);
		i++;
	}
}

/*
*/
void	init_philosopher(t_ctrl *control)
{
	t_philo	*philo;

	philo = (t_philo *)ft_malloc(sizeof(t_philo), error_message);
	philo->id = 1;
	philo->color = get_color();
	philo->last_meal = control->start_time;
	philo->last_action = control->start_time;
	philo->meal_times = 0;
	philo->control = control;
	if (pthread_create(&control->threads[0], NULL, &simulation_one_philosopher,
			(void *)philo))
		exit_program(control, ERROR_THREAD);
	if (pthread_join(control->threads[0], NULL))
		exit_program(control, ERROR_THREAD);
	free(philo);
}
