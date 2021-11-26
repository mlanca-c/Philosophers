/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:48:08 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/26 17:55:29 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** This function initializes the 'fork' - struct s_fork - variable in
** 'controllers'.
** It allocates the necessary space for the variable. It sets 'philo_id' to it's
** default - 0 - and then initializes the 'mutex_fork' using the
** pthread_mutex_init() function.
**
** @param	t_ctrl	*controllers	- main variable of the program. Its use in
** 									init_fork() function is mainly in case of
** 									error - if pthread_mutex_init() function
** 									returns a valu different than 0 - error -
** 									then exit_program() function is called with
** 									controllers as its argument so that it can
** 									be properly freed.
**
** @return
** 		- the init_fork() function returns a fork - struct s_fork - variable to
** 		the variable 'controllers'.
*/
t_fork	*init_fork(t_ctrl *controllers, t_error *error)
{
	t_fork	*fork;
	int		i;

	fork = (t_fork *)ft_malloc(sizeof(t_fork) * controllers->nu_philo,
			error, MALLOC_FORK);
	if (*error)
		return (fork);
	i = 0;
	while (i < controllers->nu_philo)
	{
		fork[i].used = false;
		if (pthread_mutex_init(&(fork[i++].mutex), NULL))
		{
			while (i)
				pthread_mutex_destroy(&(fork[--i].mutex));
			*error = INIT_FORK;
		}
	}
	return (fork);
}
