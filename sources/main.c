/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:44:04 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/25 11:57:51 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** This is the main function of the program. The main() function will validate
** the user's command line arguments. Then it will initiate the 'controllers'
** variable - main variable of the project - and then it will begin the 
** philosophers simulation by initilializing the threads - philosophers.
** The simulation is different depending on the number of philosophers - the
** program has specifications with the 1 philosopher's case.
**
** @param	int		argc	- argument counter.
** @param	char	*argv	- command line arguments.
*/
int	main(int argc, char *argv[])
{
	t_ctrl	*controllers;

	if (argc > 1 && !ft_strcmp(argv[1], "--help"))
		help_message();
	if (argc < 5 || argc > 6)
		error_message(INVALID_ARGS_NUM);
	controllers = init_controllers(argc, argv);
	if (controllers->nu_philo == 1)
		init_thread(controllers);
	else
		init_threads(controllers);
	return (0);
}
