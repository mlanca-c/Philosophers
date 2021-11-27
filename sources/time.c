/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:42:31 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/27 00:18:29 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** This function gives the current time of day in millisecods.
** It uses the gettimeofday() function to get the current seconds - 'tv_sec' -
** and the current microseconds - 'tv_usec'.
**
** @return
** 		- The get_current_time() function returns the current time of day in
** 		milliseconds.
*/
t_ms	get_curr_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((t_ms)((time.tv_sec * 1000) + (time.tv_usec / 1000)));
}

/*
** This function counts the time 'time' in milliseconds.
** The way it does so is by checking if the time that has passed since
** philo->last_action if bigger that time.
** It mimics the behavior of usleep function of the C library, but with a few
** changes: mainly on precision (this one is better), but also by checking if
** the philosopher isn't dead - This means that the thread isn't really asleep
** so its more heavy than usleep() function.
**
** @param	t_ms	time	- time in milliseconds 'philo' is supposed to sleep.
** @param	t_philo	*philo	- philosopher that is 'sleeping'.
*/
void	ft_usleep(t_ms time, t_philo *philo)
{
	while (time > (get_curr_time() - philo->last_action))
	{
		is_dead(philo);
		if (philo->controllers->death)
			break ;
	}
}
