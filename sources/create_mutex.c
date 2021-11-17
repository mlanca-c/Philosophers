/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <mlanca-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:04:26 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/16 23:56:14 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** This function initializes the mutexes 'mutex_print' and 'mutex_dead' in the
** control struct - t_ctrl *control.
**
** @param	t_ctrl	*control	- main struct of the program. Contains all
** 								necessary program variables.
*/
void	init_mutex(t_ctrl *control)
{
	control->mutex_print = (pthread_mutex_t *)ft_malloc(sizeof(pthread_mutex_t),
			error_message);
	control->mutex_dead = (pthread_mutex_t *)ft_malloc(sizeof(pthread_mutex_t),
			error_message);
	if (pthread_mutex_init(control->mutex_print, NULL))
		exit_program(control, ERROR_MUTEX);
	if (pthread_mutex_init(control->mutex_dead, NULL))
		exit_program(control, ERROR_MUTEX);
}

/*
** The destroy_mutex() function is pretty self explanatory: it destroys the
** control->mutexes list created by the init_mutex() function as well as the
** 'mutex_print' and the 'mutex_dead' variables of the control - t_ctl control -
** struct.
** This function is called by the exit_program() function, when the program is
** finishing.
**
** @param	t_ctrl	*control	- main struct of the program. Contains all
** 								necessary program variables.
*/
void	destroy_mutex(t_ctrl *control)
{
	int	i;

	i = 0;
	while (i < control->nu_of_philo)
		pthread_mutex_destroy(&(control->forks[i++].mutex_fork));
	pthread_mutex_destroy(control->mutex_print);
	pthread_mutex_destroy(control->mutex_dead);
	free(control->mutex_dead);
	free(control->mutex_print);
}
