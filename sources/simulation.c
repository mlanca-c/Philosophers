/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:21:21 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/27 00:03:14 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	ft_usleep(philo->controllers->time_to_die, philo);
	print_action(DIE, philo);
	return (philo);
}

/*
** This function checks if 'philo' is dead or not. If 'philo' is dead -
** if philo's time of last meal surpassed the time to die - then 'death' is set
** to true and the action DIE is printed by the dead philosopher. At this moment
** all other philosophers will realize there's been a death and will each exit
** their respective simulation().
**
** @param	t_philo	*philo	- philosopher in the simulation.
*/
void	is_dead(t_philo *philo)
{
	if (get_time(philo->last_meal) > philo->controllers->time_to_die)
	{
		pthread_mutex_lock(&(philo->controllers->print));
		if (!philo->controllers->death)
		{
			philo->controllers->death = true;
			printf("%8ums", get_time(philo->controllers->start_time));
			printf("%4d \t\t", philo->id);
			printf(FRED"%-.20s\n" RESET, DIE);
		}
		pthread_mutex_unlock(&(philo->controllers->print));
	}
}

/*
** This function returns the corresponding forks of each philosopher.
**
** @param	t_philo	*philo	- philosopher in the simulation.
** @param	int		*one	- first fork of 'philo'
** @param	int		*two	- second fork of 'philo'
*/
void	get_forks(t_philo *philo, int *one, int *two)
{
	*one = (philo->id) % philo->controllers->nu_philo;
	*two = (philo->id - 1) % philo->controllers->nu_philo;
}

/*
** This is the function that represents the simulation of the philosophers
** dinning problem. In here the philosopher will grab their respective forks,
** then they will eat, sleep and then do all of it over again until one
** philosopher dies or all of them are satisfied.
**
** @param	void	*arg	- argument given in pthread_create() function in
** 							init_threads().
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
		while (!philo->controllers->death && !philo->fork)
		{
			if (philo->id % 2)
				take_forks(philo, one, two);
			else
				take_forks(philo, two, one);
		}
		eat(philo);
		leave_forks(philo, one, two);
		if (philo->controllers->max_meal
			&& philo->nu_meal >= philo->controllers->max_meal)
			break ;
		sleep(philo);
		print_action(THINK, philo);
	}
	return (philo);
}
