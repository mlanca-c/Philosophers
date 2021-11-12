/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:47:54 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/12 11:58:08 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
*/
t_time	get_time(void)
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
	printf("Hello %d\n", philosopher->id);
	free(philosopher);
	return ("OK\n");
}
