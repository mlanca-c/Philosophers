/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:21:56 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/26 20:36:59 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
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
*/
void	eat(t_philo *philo)
{
	print_action(EAT, philo);
	philo->last_meal = philo->last_action;
	ft_wait(philo->controllers->time_to_eat, philo);
	philo->nu_meal++;
}

/*
*/
void	leave_forks(t_philo *philo, int one, int two)
{
	philo->controllers->fork[one].used = false;
	philo->controllers->fork[two].used = false;
	philo->fork = false;
}

void	sleep(t_philo *philo)
{
	print_action(SLEEP, philo);
	ft_wait(philo->controllers->time_to_sleep, philo);
}
