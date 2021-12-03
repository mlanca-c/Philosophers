/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:03:57 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/12/03 11:19:48 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** This function initializes a single thread.
** The init_thread() function allocates the necessary space for the thread and
** then it initializes it using the pthread_create() function. After the thread
** is initialized, it will go to the simulation_one_phiosopher() function with
** philo as its argument while the program goes to join_thread() function.
**
** @param	t_ctrl	*controllers	- main variable of the program.
** @param	t_error	*error	- variable address of an error - typedef char *.
** 							In case of error, this variable will stop being null
** 							and the function will end. The exit_program()
** 							function will then be called and 'error' will be
** 							displayed in the command line.
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
** This function initializes a list of threads.
** The init_thread() function allocates the necessary space for the threads and
** then it initializes them using the pthread_create() function. After the
** threads are initialized, they will go to the simulation() function with the
** current philo as its argument while the program goes to join_thread()
** function.
**
** @param	t_ctrl	*controllers	- main variable of the program.
** @param	t_error	*error	- variable address of an error - typedef char *.
** 							In case of error, this variable will stop being null
** 							and the function will end. The exit_program()
** 							function will then be called and 'error' will be
** 							displayed in the command line.
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
** This function performs the pthread_join() function of the lost of threads
** created in init_threads() or init_thread() function.
** The join will wait for all the threads to finish before exiting the function.
**
** @param	t_ctrl	*controllers	- main variable of the program.
*/
void	join_threads(t_ctrl *controllers)
{
	int		i;

	i = 0;
	while (i < controllers->nu_philo)
		pthread_join(controllers->thread[i++], NULL);
}
