/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:46:47 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/18 10:51:23 by mlanca-c         ###   ########.fr       */
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
void	*simulation(void *arg)
{
	t_philo	*philo;
	int	right;
	int	left;

	philo = (t_philo *)arg;
	left = (philo->id - 1) % philo->control->nu_of_philo;
	right = philo->id % philo->control->nu_of_philo;
	while (!philo->control->deaths)
	{
		if (philo->id % 2)
			philo_take_forks(philo, right, left);
		else
			philo_take_forks(philo, left, right);
		philo_eat(philo);
		philo_leave_forks(philo, right, left);
		if (philo->control->time_to_eat &&
			philo->meal_times >= philo->control->nu_meals)
			break ;
		philo_sleep(philo);
		philo_think(philo);
	}
	return (0);
}

/*
** This function checks if the philosopher - 'philo' is dead.
** The check_dead() function checks if the period of time the philosopher -
** 'philo' has gone without eating hasn't surpassed the time the philo can go
** without a meal.
**
** @param	t_philo	*philo	- philosopher in case.
*/
int	is_dead(t_philo *philo)
{
	if (get_time(philo->last_meal) > philo->control->time_to_die)
	{
		pthread_mutex_lock(philo->control->mutex_dead);
		print_action(DIE, philo);
		philo->control->deaths = TRUE;
		pthread_mutex_unlock(philo->control->mutex_dead);
		return (1);
	}
	return (0);
}
