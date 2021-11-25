/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:53:25 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/25 17:14:14 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** This function assigns the correct forks to each philosopher.
** The get_forks() function assigns the value of <philo-id> to the first fork -
** except when dealing with the last philo, in that case the value assign to
** fork_1 is 0 - and assigns to the second fork the value of <philo-id> - 1.
**
** @param	t_philo	*philo	- philo struct used to get the respective philo
** 							forks.
** @param	int		*two	- index of one of the forks available to philo in
** 							the simulation.
** @param	int		*one	- index of one of the forks available to philo in
** 							the simulation.
*/
void	get_forks(t_philo *philo, int *one, int *two)
{
	*one = philo->id % philo->controllers->nu_philo;
	*two = (philo->id  - 1) % philo->controllers->nu_philo;
}

/*
*/
bool	check_dead(t_philo *philo)
{
	if (get_time(philo->last_meal) >= philo->controllers->time_to_die)
	{
		pthread_mutex_lock(&(philo->controllers->mutex_print));
		if (!philo->controllers->death)
		{
			printf("|%ums\t", get_time(philo->controllers->start_time));
			printf("|%s%5d " RESET, philo->color, philo->id);
			printf("|%sdied.\n"RESET, RED);
			philo->controllers->death = true;
		}
		pthread_mutex_unlock(&(philo->controllers->mutex_print));
		return (true);
	}
	return (false);
}

/*
** This is a simulation in case only one philosopher exists.
** The simulation_one_phiosopher() function makes the philosopher grab the only
** fork in the table, and then starve to death.
** This case is specific because there is only one fork - the philosopher needs
** two forks in order to eat.
**
** @param	void	*arg	- argument given in pthread_create() function in
** 							init_thread.
*/
void	*simulation_one_phiosopher(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	print_action(FORK, philo);
	ft_wait(philo->controllers->time_to_die, philo);
	print_action(DIE, philo);
	return (philo);
}

/*
 * @param	void	*arg	- argument given in pthread_create() function in
 * 							init_threads.
*/
void	*simulation(void *args)
{
	t_philo	*philo;
	int		one;
	int		two;

	philo = (t_philo *)args;
	get_forks(philo, &one, &two);
	while (!philo->controllers->death)
	{
		while (!philo->has_forks)
		{
			if (philo->id % 2)
				philo_take_forks(philo, one, two);
			else
				philo_take_forks(philo, one, two);
		}
		philo_eat(philo);
		philo_leave_fork(philo, one, two);
		if (philo->controllers->max_meal && 
				philo->nu_meal >= philo->controllers->max_meal)
			break ;
		philo_sleep(philo);
		print_action(THINK, philo);
	}
	return (philo);
}
