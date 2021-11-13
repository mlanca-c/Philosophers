/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:15:53 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/13 15:36:30 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** This function is called if the command line argument is ./philo --help.
** This will display to the user the desired input for the program. The function
** then exits the program with EXIT_SUCCESS.
*/
void	help_message(void)
{
	printf("\n[ " ANSI_GREEN "ok" ANSI_RESET " ]:\t\t");
	printf("./philo 1 800 200 200 7\n");
	printf("[ " ANSI_GREEN "format" ANSI_RESET " ]:\t");
	printf("./philo <num_philo> <time_to_die> <time_to_eat> ");
	printf("<time_to_sleep> [num_times_each_philo_must_eat]\n");
	exit(EXIT_SUCCESS);
}

/*
** This function is called if the command line arguments given by the user are
** not in the correct format:
**		./philo <num_philo> <time_to_die> <time_to_eat> <time_to_sleep>
**										[num_times_each_philo_must_eat]
**
** If so, the error_message() function displays an error message, and exits the
** program with EXIT_FAILURE.
** This function takes no arguments and ends the program when called.
**
** @param	char	*message	- message to be displayed to the user.
*/
void	error_message(char *message)
{
	printf("\n[ " ANSI_RED "philosophers" ANSI_RESET " ]: %s", message);
	printf("[ "ANSI_RED "info" ANSI_RESET " ]: ./philo --help\n");
	exit(EXIT_FAILURE);
}

/*
** This function is called once the simulation ends - either a philosopher dies
** or every philosopher ate the maximum amount of times it could.
** The function frees all allocated memory and destroys all threads and mutex.
** Finally, it exits the program with EXIT_SUCCESS.
**
** @param	t_ctrl	*control	- main struct of the program. Some variables
** 								it contains need to be freed.
*/
	/*
	if (message != ERROR_THREADS && message != ERROR_MUTEX)
		destroy_threads(control);
	*/
void	exit_program(t_ctrl *control, int message)
{
	if (message != ERROR_MUTEX)
		destroy_mutex(control);
	free(control->mutexes);
	free(control->threads);
	free(control);
	exit(EXIT_SUCCESS);
}
