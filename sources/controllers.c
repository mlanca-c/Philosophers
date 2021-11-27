/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controllers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:55:25 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/27 00:19:02 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** This function does the parsing of the user's input - command line arguments -
** storing the values to their respective space in 'controllers'.
** If the values are correct, then the parsing function returns to controllers
** with error being NULL. Else error will be equal to INVALID_ARGS.
**
** @param	t_ctrl	*controllers	- main variable of the program.
** @param	int		argc	- argument counter.
** @param	char	*argv	- command line arguments.
** @param	t_error	*error	- variable address of an error - typedef char *.
** 							In case of error, this variable will stop being null
** 							and the function will end. The exit_program()
** 							function will then be called and 'error' will be
** 							displayed in the command line.
*/
void	parsing(t_ctrl *controllers, int argc, char *argv[], t_error *error)
{
	int	i;

	i = 1;
	if (!ft_atoi(&controllers->nu_philo, argv[i++], error))
		return ;
	if (controllers->nu_philo > MAX_PHILO)
		*error = INVALID_ARGS;
	if (!ft_atoi((int *)&controllers->time_to_die, argv[i++], error))
		return ;
	if (!ft_atoi((int *)&controllers->time_to_eat, argv[i++], error))
		return ;
	if (!ft_atoi((int *)&controllers->time_to_sleep, argv[i++], error))
		return ;
	if (argc != i)
	{
		if (!ft_atoi(&controllers->max_meal, argv[i++], error))
			return ;
	}
	else
		controllers->max_meal = 0;
}

/*
** This function initializes the main variable of the program - struct
** s_controllers 'controllers'.
** The init_controllers() function allocates the necessary space for the
** variable controllers using the ft_malloc() function. Then parses the user's
** input given by the command line arguments. Then initializes other struct
** variables inside controllers - fork, philo, thread, print - and sets the
** non-struct variables to their default values.
**
** @param	int		argc	- argument counter.
** @param	char	*argv	- command line arguments.
** @param	t_error	*error	- variable address of an error - typedef char *.
** 							In case of error, this variable will stop being null
** 							and the function will end. The exit_program()
** 							function will then be called and 'error' will be
** 							displayed in the command line.
**
** @return
** 		- The init_controllers() function returns the struct s_controllers
** 		variable already initialized to the main() function.
*/
t_ctrl	*init_controllers(int argc, char *argv[], t_error *error)
{
	int		i;
	t_ctrl	*controllers;

	controllers = (t_ctrl *)ft_malloc(sizeof(t_ctrl), error, MALLOC_CTRL);
	if (*error)
		return (controllers);
	i = 1;
	parsing(controllers, argc, argv, error);
	if (*error)
		return (controllers);
	if (pthread_mutex_init(&(controllers->print), NULL))
	{
		*error = INIT_PRINT;
		return (controllers);
	}
	controllers->death = false;
	controllers->fork = init_fork(controllers, error);
	if (*error)
		return (controllers);
	controllers->start_time = get_curr_time();
	controllers->philo = init_philo(controllers, error);
	if (*error)
		return (controllers);
	return (controllers);
}
