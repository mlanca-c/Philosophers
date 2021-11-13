/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:47:54 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/13 17:50:39 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** This function returns the time difference between the initializing of the
** control - t_ctrl - variable and the current time in milliseconds.
**
** @param	t_ctrl	*control	- main struct of the program that contains the
** 								variable start_time - t_time. Time the
** 								simulation started in milliseconds.
**
** @return
** 		- The get_time() function returns the difference between the current
** 		time and the start_time in milliseconds.
*/
t_time	get_time(t_ctrl *control)
{
	return (get_current_time() - control->start_time);
}

/*
** This function returns the current time in milliseconds. The
** get_current_time() time function makes use of the gettimeofday() function.
**
** @return
** 		- The get_current_time() function returns the current time in
** 		milliseconds.
*/
t_time	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((t_time)(time.tv_sec * 1000 + time.tv_usec / 1000));
}

/// TO DELETE
void	*say_hello(void *philo)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)philo;
	printf("|%lums\t| Philosopher %d says Hello\n",
		get_time(philosopher->control), philosopher->id);
	return ("OK\n");
}
