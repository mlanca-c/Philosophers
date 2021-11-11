/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:47:54 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/11 19:40:43 by mlanca-c         ###   ########.fr       */
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
void	*say_hello(void *control)
{
	static int	i = 0;

	printf("Hello %d\n", i++);
	return (control);
}
