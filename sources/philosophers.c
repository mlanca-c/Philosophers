/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 22:31:51 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/06 22:40:27 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
*/
t_philo	*init_philosophers(t_ctrl *control)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)ft_malloc(sizeof(t_philo) * control->nu_of_philo,
			error_message);
	i = 0;
	while (i < control->nu_of_philo)
	{
		philos[i].name = i + 1;
		//philos[i].color = get_philos_color(i + 1);
		philos[i].status = THINKING;
		philos[i].times_philo_ate = 0;
		philos[i++].control = control;
	}
	return (philos);
}
