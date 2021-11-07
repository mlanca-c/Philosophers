/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 22:31:51 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/07 16:28:43 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
*/
char	*get_philos_color(int name)
{
	if (name % 7 == 0)
		return (ANSI_RED);
	if (name % 7 == 1)
		return (ANSI_GREEN);
	if (name % 7 == 2)
		return (ANSI_YELLOW);
	if (name % 7 == 3)
		return (ANSI_BLUE);
	if (name % 7 == 4)
		return (ANSI_MAGENTA);
	if (name % 7 == 5)
		return (ANSI_CYAN);
	if (name % 7 == 6)
		return (ANSI_WHITE);
	return (ANSI_RESET);
}

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
		philos[i].color = get_philos_color(i + 1);
		philos[i].status = THINKING;
		philos[i].times_philo_ate = 0;
		philos[i].control = control;
		i++;
	}
	return (philos);
}
