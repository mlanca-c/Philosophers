/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:57:32 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/08 10:28:26 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_ctrl *control)
{
	int	i;

	i = 0;
	while (i < control->nu_of_philo)
	{
		if (pthread_create(control->philosophers[i].thread, NULL, NULL, NULL))
		{
			while (i)
				pthread_detach(control->philosophers[i].thread);
			printf("Destroyed Threads ...\n");
			exit_program(control, ERROR_THREAD);
		}
		i++;
	}
	printf("Created Threads ...\n");
}

void	destroy_threads(t_ctrl *control)
{
	int	i;

	i = 0;
	while (i < control->nu_of_philo)
		pthread_detach(control->philosophers[i++].thread);
}
