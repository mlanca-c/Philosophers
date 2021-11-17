/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:31:01 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/16 23:47:49 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** This function initializes the struct forks in 'control' - t_ctrl *.
** It first allocates the necessary space for the variable - in this case, it
** allocates the size of t_fork times the number of philosophers. Then each
** fork is assigned a philo_id: -1 as default; and a mutex: mutex_fork that is
** initialized in the function as well.
**
** @param	t_ctrl	*control	- main variable of the program. It contains the
** 								list of forks initialized in this function.
*/
void	init_forks(t_ctrl *control)
{
	int	i;

	control->forks = (t_fork *)ft_malloc(sizeof(t_fork) * control->nu_of_philo,
			error_message);
	i = 0;
	while (i < control->nu_of_philo)
	{
		control->forks[i].philo_id = -1;
		if (pthread_mutex_init(&(control->forks[i].mutex_fork), NULL))
		{
			while (i)
				pthread_mutex_destroy(&(control->forks[--i].mutex_fork));
			exit_program(control, ERROR_MUTEX);
		}
		i++;
	}
}
