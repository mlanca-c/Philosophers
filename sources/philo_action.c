/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:46:41 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/14 15:55:19 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
*/
void	philo_think(t_philo *philo)
{
	philo->status = THINKING;
	print_action(THINK, philo);
}

/*
*/
void	philo_take_forks(t_philo *philo)
{
	int	right_fork;
	int	left_fork;

	pthread_mutex_lock(philosopher->control->mutexes[right_fork]);
	pthread_mutex_lock(philosopher->control->mutexes[left_fork]);
	philo->status = HAS_FORKS;
	print_action(FORKS, philo);
}

/*
*/
void	philo_eat(void *philo)
{
	philo->times_philo_ate++;
	philo->status = EATING;
	print_action(EAT, philo);
	ft_wait(philo, philo->control->time_to_eat);
}

/*
*/
void	philo_leave_forks(t_philo *philo)
{
	int	right_fork;
	int	left_fork;

	pthread_mutex_unlock(philosopher->control->mutexes[right_fork]);
	pthread_mutex_unlock(philosopher->control->mutexes[left_fork]);
}

/*
*/
void	philo_sleep(t_philo *philo)
{
	philo->status = SLEEPING;
	print_action(SLEEP, philo);
	ft_wait(philo->control->time_to_sleep);
}
