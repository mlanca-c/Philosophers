/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:46:47 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/15 18:57:41 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
*/
void	*simulation_one_philosopher(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	print_action(FORK, philo);
	ft_wait(philo->control->time_to_die, philo);
	print_action(DIE, philo);
	return (0);
}

/*
*/
void	*simulation(void *arg);

/*
** This function checks if the philosopher - 'philo' is dead.
** The check_dead() function checks if the period of time the philosopher -
** 'philo' has gone without eating hasn't surpassed the time the philo can go
** without a meal.
**
** @param	t_philo	*philo	- philosopher in case.
*/
t_bool	is_dead(t_philo *philo)
{
	if (get_time(philo->last_meal) > philo->control->time_to_die)
	{
		philo->control->deaths = TRUE;
		return (TRUE);
	}
	return (FALSE);
}
