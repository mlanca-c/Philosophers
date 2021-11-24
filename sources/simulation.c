/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:53:25 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/24 17:06:06 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** This function assigns the correct forks to each philosopher.
** The get_philo_forks() function assigns the value of <philo-id> to the first
** fork - except when dealing with the last philo, in that case the value assign
** to fork_1 is 0 - and assigns to the second fork the value of <philo-id> - 1.
**
** @param	t_philo	*philo	- philo struct used to get the respective philo
** 							forks.
** @param	int		*fork_1	- index of one of the forks available to philo in
** 							the simulation.
** @param	int		*fork_2	- index of one of the forks available to philo in
** 							the simulation.
*/
void	get_philo_forks(t_philo *philo, int *fork_1, int *fork_2)
{
	*fork_1 = philo->id % philo->controllers->nu_philo;
	*fork_2 = (philo->id  - 1) % philo->controllers->nu_philo;
}

/*
*/
void	check_dead(t_philo *philo)
{
	if (get_time_from_action(philo->last_meal) >= philo->controllers->time_to_die)
	{
		pthread_mutex_lock(&(philo->controllers->mutex_die));
		if (!philo->controllers->death)
			print_action(DIE, philo);
		philo->controllers->death = true;
		pthread_mutex_unlock(&(philo->controllers->mutex_die));
	}
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
 * This function ...!!!
 * @param	void	*arg	- argument given in pthread_create() function in
 * 							init_threads.
*/
void	*simulation(void *args)
{
	t_philo	*philo;
	int		fork_1;
	int		fork_2;

	philo = (t_philo *)args;
	get_philo_forks(philo, &fork_1, &fork_2);
	while (1)
	{
		if (philo->id % 2)
			philo_take_forks(philo, fork_1, fork_2);
		else
			philo_take_forks(philo, fork_2, fork_1);
		check_dead(philo);
		if (philo->controllers->death)
			break ;
	}
	return (philo);
}
