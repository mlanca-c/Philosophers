/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:22:46 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/25 17:24:03 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
*/
void	print_action(char *action, t_philo *philo)
{
	if (ft_strcmp(action, FORK))
		philo->last_action = get_current_time();
	pthread_mutex_lock(&(philo->controllers->mutex_print));
	if (check_dead(philo))
		return ;
	printf("|%ums\t", get_time(philo->controllers->start_time));
	printf("|%s%5d " RESET, philo->color, philo->id);
	printf("|%s\n", action);
	pthread_mutex_unlock(&(philo->controllers->mutex_print));
}
