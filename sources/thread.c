/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:18:33 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/23 18:16:30 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
*/
void	init_thread(t_ctrl *controllers)
{
	controllers->thread = (pthread_t *)ft_malloc(sizeof(pthread_t),
			error_message);
	if (pthread_create(controllers->thread, NULL, &simulation_one_phiosopher,
				controllers->philo))
		exit_program(controllers, EXIT_THREAD);
	remove_thread(controllers);
}

/*
*/
void	init_threads(t_ctrl *controllers)
{
	int	i;

	i = controllers->nu_philo;
	controllers->thread = (pthread_t *)ft_malloc(sizeof(pthread_t) * i,
			error_message);
	i = 0;
	while (i < controllers->nu_philo)
	{
		if (pthread_create(&(controllers->thread[i]), NULL, &simulation,
					&(controllers->philo[i])))
			exit_program(controllers, EXIT_THREAD);
		i++;
	}
	remove_thread(controllers);
}

/*
*/
void	remove_thread(t_ctrl *controllers)
{
	int	i;

	i = 0;
	while (i < controllers->nu_philo)
	{
		pthread_join(controllers->thread[i], NULL);
		i++;
	}
}
