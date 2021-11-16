/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:06:36 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/16 10:09:57 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
*/
void	print_action(char *message, t_philo *philo)
{
	printf("|%lums", get_time(philo->last_action));
	printf("\t|%sPhilosopher %d" ANSI_RESET, philo->color, philo->id);
	printf("\t%s", message);
}
