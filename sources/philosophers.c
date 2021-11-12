/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 22:31:51 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/12 12:30:10 by mlanca-c         ###   ########.fr       */
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
char	*get_philos_color(int id)
{
	if (id % 7 == 0)
		return (ANSI_RED);
	if (id % 7 == 1)
		return (ANSI_GREEN);
	if (id % 7 == 2)
		return (ANSI_YELLOW);
	if (id % 7 == 3)
		return (ANSI_BLUE);
	if (id % 7 == 4)
		return (ANSI_MAGENTA);
	if (id % 7 == 5)
		return (ANSI_CYAN);
	return (ANSI_WHITE);
}

/*
** This function initializes a struct s_philosopher - t_philo according to the
** number of philos. It allocates the necessary space for a t_philo type and
** then it sets all t_philo attributes to its default:
** 	- id: it's set to the index of the philosophers - 1 in the 'control' list.
** 	- color: it's set to a certain color depending on the philos id using the
** 			get_philos_color() function.
** 	- status: it's set to the enum THINKING.
** 	- last_ate: it's set to -1, cause the philosopher hasn't eaten yet.
** 	- times_philo_ate: it's set to 0.
** 	- is_dead: it's set to FALSE.
** It then calls the init_thread() function to create a thread that will go to
** the simulation() function with the philosopher as its parameter.
** @return
** 		- The init_philosophers() function returns the list of philosophers to
** 		the control variable or exits the program with EXIT_FAILURE in case of
** 		error.
*/
t_philo	*init_philosophers(t_ctrl *control)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < control->nu_of_philo)
	{
		philo = (t_philo *)ft_malloc(sizeof(t_philo), error_message);
		philo->id = i + 1;
		philo->color = get_philos_color(i + 1);
		philo->status = THINKING;
		philo->last_ate = -1;
		philo->times_philo_ate = 0;
		philo->is_dead = FALSE;
		philo->control = control;
		init_thread(control, philo);
		i++;
	}
	return (philo);
}
