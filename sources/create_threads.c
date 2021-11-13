/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:57:32 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/13 16:25:49 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** This function is called by the init_control() function. The malloc_threads()
** function allocates the necessary space for the control->threads - list of
** threads.
**
** @param	t_ctrl	*control	- main struct of the program. Contains all
** 								necessary program variables.
*/
void	malloc_threads(t_ctrl *control)
{
	int	i;

	i = control->nu_of_philo;
	control->threads = (pthread_t *)ft_malloc(sizeof(pthread_t) * i,
			error_message);
}

/*
** This function is called by the init_philosophers() function. The
** create_threads() creates a thread, gives it a function - 'simulation()' and a
** parameter for that function - the philosopher associated with the thread.
**
** @param	t_ctrl	*control		- main struct of the program. Contains all
** 									necessary program variables.
** @param	t_philo *philosopher	- philosopher struct. It will be the param
** 									given to the simulation() function.
*/
void	init_thread(t_ctrl *control, t_philo *philosopher)
{
	static int	i = 0;

	if (pthread_create(&control->threads[i], NULL, &say_hello,
			(void *)philosopher))
		exit_program(control, ERROR_THREAD);
	if (pthread_join(control->threads[i], NULL))
		exit_program(control, ERROR_THREAD);
	free(philosopher);
	i++;
}
