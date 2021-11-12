/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <mlanca-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:04:26 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/12 12:21:54 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** This function initializes the mutexes - control->mutexes (pthread_mutex_t *).
** It allocates the necessary space and then creates the mutexes using the
** pthread_mutex_init() function.
** If the pthread_mutex_init() function fails at initializing a thread, then the
** function starts destroying the already created mutexes and then exits the
** function with exit_program() function.
**
** @param	t_ctrl	*control	- main struct of the program. Contains all
** 								necessary program variables.
*/
void	init_mutex(t_ctrl *control)
{
	int	i;

	i = control->nu_of_philo;
	control->mutexes = (pthread_mutex_t *)ft_malloc(sizeof(pthread_mutex_t) * i,
			error_message);
	i = 0;
	while (i < control->nu_of_philo)
	{
		if (pthread_mutex_init(&(control->mutexes[i]), NULL))
		{
			while (i)
				pthread_mutex_destroy(&(control->mutexes[--i]));
			exit_program(control, ERROR_MUTEX);
		}
		i++;
	}
}

/*
** The destroy_mutex() function is pretty self explanatory: it destroys the
** control->mutexes list created by the init_mutex() function.
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
		pthread_mutex_destroy(&(control->mutexes[i++]));
}
