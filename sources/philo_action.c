/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:46:41 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/17 10:29:52 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
*/
void	philo_take_forks(t_philo *philo, int right, int left)
{
	pthread_mutex_lock(&philo->control->forks[right].mutex_fork);
	pthread_mutex_lock(&philo->control->forks[left].mutex_fork);
	if (philo->control->forks[right].philo_id == -1)
	{
		philo->control->forks[right].philo_id = philo->id;
		print_action(FORK, philo);
	}
	if (philo->control->forks[left].philo_id == -1)
	{
		philo->control->forks[left].philo_id = philo->id;
		print_action(FORK, philo);
	}
	pthread_mutex_unlock(&philo->control->forks[right].mutex_fork);
	pthread_mutex_unlock(&philo->control->forks[left].mutex_fork);
	is_dead(philo);
}

/*
*/
void	philo_eat(t_philo *philo)
{
	print_action(EAT, philo);
	philo->meal_times++;
	ft_wait(philo->control->time_to_eat, philo);
}

/*
*/
void	philo_leave_forks(t_philo *philo, int right, int left)
{
	philo->control->forks[right].philo_id = -1;
	philo->control->forks[left].philo_id = -1;
}

/*
*/
void	philo_sleep(t_philo *philo)
{
	print_action(SLEEP, philo);
	ft_wait(philo->control->time_to_sleep, philo);
}

/*
*/
void	philo_think(t_philo *philo)
{
	print_action(THINK, philo);
}
