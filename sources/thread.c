/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:03:57 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/26 18:37:46 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 * This function initializes a single thread.
 * The init_thread() function allocates the necessary space for the thread and
 * then it initializes it using the pthread_create() function. After the thread
 * is initialized, it will go to the simulation_one_phiosopher() function with
 * philo as its argument while the program goes to remove_thread() function.
*/
void	init_thread(t_ctrl *controllers, t_error *error)
{
	controllers->thread = (pthread_t *)ft_malloc(sizeof(pthread_t),
			error, MALLOC_THREAD);
	if (*error)
		return ;
	if (pthread_create(controllers->thread, NULL, &simulation_one_phiosopher,
			controllers->philo))
	{
		*error = INIT_THREAD;
		return ;
	}
	join_threads(controllers);
}

/*
*/
void	init_threads(t_ctrl *controllers, t_error *error)
{
	int	i;

	i = controllers->nu_philo;
	controllers->thread = (pthread_t *)ft_malloc(sizeof(pthread_t) * i,
			error, MALLOC_THREAD);
	if (*error)
		return ;
	i = 0;
	while (i < controllers->nu_philo)
	{
		if (pthread_create(&(controllers->thread[i]), NULL, &simulation,
				&(controllers->philo[i])))
		{
			*error = INIT_THREAD;
			return ;
		}
		i++;
	}
	join_threads(controllers);
}

/*
*/
void	join_threads(t_ctrl *controllers)
{
	int		i;
	t_error	error;

	i = 0;
	error = NULL;
	while (i < controllers->nu_philo)
	{
		pthread_join(controllers->thread[i], NULL);
		i++;
	}
}
