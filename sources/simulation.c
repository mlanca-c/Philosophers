/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:46:47 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/14 13:45:23 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
*/
void	*simulation_one_philosopher(void *arg)
{
	t_philo	*philosopher;
	t_ctrl	*control;

	philosopher = (t_philo *)arg;
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

/*
*/
void	*simulation(void *arg)
{
	t_philo	*philo;

	philo = (t_ctrl *)arg;
	while (!philo->control->deaths)
	{
		philo_think(philo);
		philo_take_forks(philo);
		philo_eat(philo);
		philo_leave_forks(philo);
		if (philo->control->nu_of_time_to_eat && 
			philo->times_philo_ate == philo->control->nu_of_time_to_eat)
			break ;
		philo_sleep(philo);
	}
	return (EXIT_SUCCESS);
}
