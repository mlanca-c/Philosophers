/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:06:36 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/15 18:56:05 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
*/
void	print_action(char *message, t_philo *philo)
{
	t_time	time;

	time = get_time(get_current_time());
	printf("|%lums", get_time(philo->last_action));
	printf("\t|Philosopher %d", philo->id);
	printf("\t%s", message);
}
