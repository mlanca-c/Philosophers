/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:31:15 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/27 00:19:52 by mlanca-c         ###   ########.fr       */
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
		philo->last_action = get_curr_time();
	printf("%8ums", get_curr_time() - philo->controllers->start_time);
	printf("%s%4d \t\t", philo->color, philo->id);
	printf("%-.20s\n" RESET, action);
	pthread_mutex_unlock(&(philo->controllers->print));
}
