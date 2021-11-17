/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <mlanca-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:57:32 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/17 00:08:54 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
void	init_thread(t_ctrl *control)
{
	int	i;

	i = control->nu_of_philo;
	control->threads = (pthread_t *)ft_malloc(sizeof(pthread_t) * i,
			error_message);
	i = 0;
	while (i < control->nu_of_philo)
	{
		if (pthread_create(&(control->threads[i]), NULL, &simulation,
				(void *)(&control->philos[i])))
			exit_program(control, ERROR_THREAD);
		i++;
	}
}

/*
*/
void	destroy_threads(t_ctrl *control)
{
	int	i;

	i = 0;
	while (i < control->nu_of_philo)
	{
		if (pthread_join(control->threads[i++], NULL))
			exit_program(control, ERROR_THREAD);
	}
}
