/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:42:31 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/25 16:04:18 by mlanca-c         ###   ########.fr       */
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
t_ms	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((t_ms)((time.tv_sec * 1000) + (time.tv_usec / 1000)));
}

/*
*/
t_ms	get_time(t_ms action)
{
	return (get_current_time() - action);
}

/*
*/
void	ft_wait(t_ms time, t_philo *philo)
{
	while (time > get_time(philo->last_action))
		check_dead(philo);
}
