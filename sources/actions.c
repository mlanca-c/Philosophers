/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:21:56 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/26 23:46:57 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** This function represents a philosopher's action, in this case the action of
** grabbing a fork.
** In take_forks() function a philosopher tries to grab both forks - in case
** they weren't taken by another philosopher yet. At the end of the function
** is_dead() is checked.
**
** @param	t_philo	*philo	- struct s_philo - philosopher performimg the
** 							'action'.
** @param	int		one		- one of the philosopher forks.
** @param	int		two		- one of the philosopher forks.
*/
void	take_forks(t_philo *philo, int one, int two)
{
	pthread_mutex_lock(&(philo->controllers->fork[one].mutex));
	pthread_mutex_lock(&(philo->controllers->fork[two].mutex));
	if (!philo->controllers->death && !philo->controllers->fork[one].used
		&& !philo->controllers->fork[two].used)
	{
		philo->controllers->fork[one].used = true;
		philo->controllers->fork[two].used = true;
		philo->fork = true;
		print_action(FORK, philo);
		print_action(FORK, philo);
	}
	pthread_mutex_unlock(&(philo->controllers->fork[one].mutex));
	pthread_mutex_unlock(&(philo->controllers->fork[two].mutex));
	is_dead(philo);
}

/*
** This function represents a philosopher's action, in this case, the action of
** eating.
** In eat() function a philosopher outputs that is eating and then takes
** time_to_eat milliseconds to do so.
**
** @param	t_philo	*philo	- struct s_philo - philosopher performimg the
** 							'action'.
*/
void	eat(t_philo *philo)
{
	print_action(EAT, philo);
	philo->last_meal = philo->last_action;
	ft_usleep(philo->controllers->time_to_eat, philo);
	philo->nu_meal++;
}

/*
** This function represents a philosopher's action, in this case the action of
** leaving both forks.
** In leave_forks() function a philosopher leaves both forks making them
** available to other philosophers.
**
** @param	t_philo	*philo	- struct s_philo - philosopher performimg the
** 							'action'.
** @param	int		one		- one of the philosopher forks.
** @param	int		two		- one of the philosopher forks.
*/
void	leave_forks(t_philo *philo, int one, int two)
{
	philo->controllers->fork[one].used = false;
	philo->controllers->fork[two].used = false;
	philo->fork = false;
}

/*
** This function represents a philosopher's action of sleeping.
** In sleep() function a philosopher outputs that is sleeping and then takes
** time_to_sleep in milliseconds to do so.
**
** @param	t_philo	*philo	- struct s_philo - philosopher performimg the
** 							'action'.
*/
void	sleep(t_philo *philo)
{
	print_action(SLEEP, philo);
	ft_usleep(philo->controllers->time_to_sleep, philo);
}
