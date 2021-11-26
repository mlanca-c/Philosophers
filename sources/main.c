/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:44:04 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/26 18:34:05 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 * This is the main function of the program. The main() function will validate
 * the user's command line arguments. Then it will initiate the 'controllers'
 * variable - main variable of the project - and then it will begin the 
 * philosophers simulation by initilializing the thread - representing each 
 * philosopher.
 * The simulation is different depending on the number of philosophers - the
 * program has specifications with the 1 philosopher's case.
 *
 * @param	int		argc	- argument counter.
 * @param	char	*argv	- command line arguments.
 *
 * Since using the exit() function is forbidden, the t_error - 'error' -
 * variable is used to check for errors and the exit_program() function is
 * called once 'error' isn't NULL anymore.
*/
int	main(int argc, char *argv[])
{
	t_ctrl	*controllers;
	t_error	error;

	if (argc > 1 && !ft_strcmp(argv[1], "--help"))
		return (help_message());
	if (argc < 5 || argc > 6)
		return (error_message(INVALID_ARGS));
	error = NULL;
	controllers = init_controllers(argc, argv, &error);
	if (error)
		return (exit_program(controllers, error));
	if (controllers->nu_philo == 1)
		init_thread(controllers, &error);
	else
		init_threads(controllers, &error);
	return (exit_program(controllers, error));
}
