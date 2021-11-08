/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <mlanca-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:04:26 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/08 10:26:13 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_mutex(t_ctrl *control)
{
	int	i;

	i = 0;
	while (i < control->nu_of_philo)
	{
		if (pthread_mutex_init(&(control->forks[i].mutex), NULL))
		{
			while (i)
				pthread_mutex_destroy(&(control->forks[--i].mutex));
			printf("Destroyed Mutex ...\n");
			exit_program(control, ERROR_MUTEX);
		}
		i++;
	}
	printf("Created Mutex ...\n");
}

void	destroy_mutex(t_ctrl *control)
{
	int	i;

	i = 0;
	while (i < control->nu_of_philo)
		pthread_mutex_destroy(&(control->forks[i++].mutex));
}
