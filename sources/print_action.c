/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:22:46 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/24 17:29:07 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(char *action, t_philo *philo)
{
	if (ft_strcmp(action, FORK) && ft_strcmp(action, DIE))
		philo->last_action = get_current_time();
	pthread_mutex_lock(&(philo->controllers->mutex_print));
	printf("|%ums\t", get_time_from_action(philo->controllers->start_time));
	printf("|%s%5d " RESET, philo->color, philo->id);
	printf("|%s\n", action);
	pthread_mutex_unlock(&(philo->controllers->mutex_print));
}

void	print_faction(char *action, int fork, t_philo *philo)
{
	if (ft_strcmp(action, FORK) && ft_strcmp(action, DIE))
		philo->last_action = get_current_time();
	pthread_mutex_lock(&(philo->controllers->mutex_print));
	printf("|%ums\t", get_time_from_action(philo->controllers->start_time));
	printf("|%s%5d " RESET, philo->color, philo->id);
	if (!ft_strcmp(action, DIE))
		printf(RED);
	printf("|%s %d\n"RESET, action, fork);
	pthread_mutex_unlock(&(philo->controllers->mutex_print));
}
