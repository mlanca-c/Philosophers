/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:28:52 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/16 10:12:02 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

/*
** This function returns the time it took a philosopher between 'time' and the
** current time, in milliseconds.
** It serves to now how much time has passed since a philosopher did a certain
** action - the 'time' is the time in milliseconds the philosopher finished its
** last action.
**
** @param	t_time	time	- time in milliseconds the philosopher started doing
** 							something.
**
** @return
** 		- This function returns the time difference in milliseconds of the
** 		argument 'time' - t_time - and the current time - get_current_time()
** 		function.
*/
t_time	get_time(t_time time)
{
	return (get_current_time() - time);
}

/*
** This function serves as a replacement of the usleep function. It makes the
** philosopher - 'philo' stop the amount of time given as a parameter - 'time'
** while at the same time checks if the philosopher hasn't died. If a
** philosopher dies while waiting, the ft_wait() function stops the counting and
** returns - breaks.
**
** @param	t_time	time	- time for the philosopher to wait.
** @param	t_philo	*philo	- philosopher in case.
*/
void	ft_wait(t_time time, t_philo *philo)
{
	while (time > get_time(philo->last_action))
	{
		if (is_dead(philo))
			break ;
	}
}

void	*say_hello(void *philos)
{
	print_action("says hello.\n", philos);
	return (0);
}
