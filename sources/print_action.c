/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:06:36 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/13 17:50:12 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
*/
void	print_action(char *message, t_philo *philosopher)
{
	t_time	time;

	time = get_time(philosopher->control);
	printf("%lums\t%s%d" ANSI_RESET "\t%s\n", time, philosopher->color,
		philosopher->id, message);
}
