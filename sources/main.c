/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:38:41 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/10 16:59:37 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** This is the main function of the program. This function does the following:
** 	- first it validates the user's input;
** 	- then it initializes the control variable;
** 	- then runs the simulation;
** 	- and last exits the program successfully having freed everything.
**
** @param	int		argc	- argument counter.
** @param	char	*argv	- command line input provided by the user.
**
** @returns
** 		- This function either ends the program successfully; or ends the
** 		program with EXIT_FAILURE in case of non-valid user arguments or malloc
** 		errors.
*/
int	main(int argc, char *argv[])
{
	t_ctrl	*control;

	if (argc > 1 && !ft_strcmp(argv[1], "--help"))
		help_message();
	else if (argc != 5 && argc != 6)
		error_message(INVALID_ARGS_NUM);
	control = init_control(argc, argv);
	if (control->nu_of_philo == 1)
		create_threads(control);
	/*
	else
		create_threads(control);
	*/
	exit_program(control, NO_ERRORS);
}
