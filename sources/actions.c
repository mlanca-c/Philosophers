/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:52:24 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/25 16:51:37 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


/*
*/
void	philo_take_forks(t_philo *philo, int one, int two)
{
	if (check_dead(philo))
		return ;
	pthread_mutex_lock(&(philo->controllers->fork[one].mutex_fork));
	pthread_mutex_lock(&(philo->controllers->fork[two].mutex_fork));
	if (!philo->controllers->fork[one].used &&
			!philo->controllers->fork[two].used)
	{
		philo->controllers->fork[one].used = true;
		print_action(FORK, philo);
		philo->controllers->fork[two].used = true;
		print_action(FORK, philo);
		philo->has_forks = true;
	}
	pthread_mutex_unlock(&(philo->controllers->fork[one].mutex_fork));
	pthread_mutex_unlock(&(philo->controllers->fork[two].mutex_fork));
}

/*
*/
void	philo_eat(t_philo *philo)
{
	print_action(EAT, philo);
	ft_wait(philo->controllers->time_to_eat, philo);
	philo->last_meal = philo->last_action;
	philo->nu_meal++;
}

/*
*/
void	philo_leave_fork(t_philo *philo, int one, int two)
{
	if (check_dead(philo))
		return ;
	philo->controllers->fork[one].used = false;
	philo->controllers->fork[two].used = false;
	philo->has_forks = false;
}

/*
*/
void	philo_sleep(t_philo *philo)
{
	print_action(SLEEP, philo);
	ft_wait(philo->controllers->time_to_sleep, philo);
}
