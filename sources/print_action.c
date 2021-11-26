/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:31:15 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/26 20:27:46 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** This function prints an action.
** The print_action() function prints an 'action' from a 'philo' with the
** fromat: <time>ms <philo_id> <action>
** If the action isn't the philosopher taking a fork, then philo->last_action is
** set to the current time.
**
** @param	char 	*action	- action the philosopher isperforming.
** @param	t_philo	*philo	- struct s_philo - philosopher performimg the
** 							'action'.
*/
void	print_action(char *action, t_philo *philo)
{
	pthread_mutex_lock(&(philo->controllers->print));
	if (philo->controllers->death)
	{
		pthread_mutex_unlock(&(philo->controllers->print));
		return ;
	}
	if (ft_strcmp(action, FORK))
		philo->last_action = get_current_time();
	printf("|%ums\t", get_time(philo->controllers->start_time));
	printf("|%s%5d " RESET, philo->color, philo->id);
	printf("|%s\n", action);
	pthread_mutex_unlock(&(philo->controllers->print));
}

void	fprint_action(char *action, t_philo *philo, int fork)
{
	if (ft_strcmp(action, FORK))
		philo->last_action = get_current_time();
	pthread_mutex_lock(&(philo->controllers->print));
	printf("|%ums\t", get_time(philo->controllers->start_time));
	printf("|%s%5d " RESET, philo->color, philo->id);
	printf("|%s %d\n", action, fork);
	pthread_mutex_unlock(&(philo->controllers->print));
}
