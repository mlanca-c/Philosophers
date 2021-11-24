/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:52:24 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/24 18:15:00 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


/*
*/
void	philo_take_forks(t_philo *philo, int fork_1, int fork_2)
{
	pthread_mutex_lock(&(philo->controllers->fork[fork_1].mutex_fork));
	if (!philo->controllers->fork[fork_1].philo_id)
	{
		print_faction(FORK, fork_1, philo);
		philo->controllers->fork[fork_1].philo_id = philo->id;
	}
	pthread_mutex_unlock(&(philo->controllers->fork[fork_1].mutex_fork));
	pthread_mutex_lock(&(philo->controllers->fork[fork_2].mutex_fork));
	if (!philo->controllers->fork[fork_2].philo_id)
	{
		print_faction(FORK, fork_2, philo);
		philo->controllers->fork[fork_2].philo_id = philo->id;
	}
	pthread_mutex_unlock(&(philo->controllers->fork[fork_2].mutex_fork));
}

/*
*/
void	philo_eat(t_philo *philo)
{
	print_action(EAT, philo);
	ft_wait(philo->controllers->time_to_eat, philo);
	philo->nu_meal++;
}

/*
*/
void	philo_leave_fork(t_philo *philo, int fork_1, int fork_2)
{
	philo->controllers->fork[fork_1].philo_id = 0;
	print_faction(FORK_L, fork_1, philo);
	philo->controllers->fork[fork_2].philo_id = 0;
	print_faction(FORK_L, fork_2, philo);
}
