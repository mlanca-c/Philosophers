/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:46:47 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/13 18:00:20 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
*/
void	*simulation_one_philosopher(void *philo)
{
	t_philo	*philosopher;
	t_ctrl	*control;

	philosopher = (t_philo *)philo;
	pthread_mutex_lock(philosopher->control->print);
	control = philosopher->control;
	printf("|%dms\t|%sPhilosopher %d", 0, philosopher->color, philosopher->id);
	printf(ANSI_RESET "\t%s\n", FORK);
	usleep(philosopher->control->time_to_die * 1000);
	printf("|%dms\t|%sPhilosopher %d", control->time_to_die, philosopher->color,
		philosopher->id);
	printf(ANSI_RESET "\t%s\n", DIE);
	pthread_mutex_unlock(philosopher->control->print);
	return (EXIT_SUCCESS);
}
