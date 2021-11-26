/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:46:19 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/26 18:18:51 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** This function is called if the command line argument is ./philo --help.
** This will display to the user the desired input for the program. The function
** then exits the program with EXIT_SUCCESS.
*/
int	help_message(void)
{
	printf("\n[ " GREEN "ok" RESET " ]:\t\t");
	printf("./philo 1 800 200 200 7\n");
	printf("[ " GREEN "format" RESET " ]:\t");
	printf("./philo <nu_philo> <time_to_die> <time_to_eat> ");
	printf("<time_to_sleep> [max_meal]\n");
	return (EXIT_SUCCESS);
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
int	error_message(char *message)
{
	printf("\n[ " RED "philosophers" RESET " ]: %s", message);
	printf("[ "RED "info" RESET " ]: ./philo --help\n");
	return (EXIT_FAILURE);
}

/*
** This function is called once the simulation ends - either a philosopher dies
** or every philosopher ate the maximum amount of times it could.
** The function frees all allocated memory and destroys all threads and mutex.
** Finally, it exits the program with EXIT_SUCCESS.
*/
int	exit_program(t_ctrl *controllers, char *error)
{
	if (!error || !ft_strcmp(error, INIT_THREAD))
		free(controllers->thread);
	if (!error || !ft_strcmp(error, MALLOC_THREAD)
		|| !ft_strcmp(error, INIT_THREAD))
		free(controllers->philo);
	if (!error || !ft_strcmp(error, MALLOC_PHILO)
		|| !ft_strcmp(error, INIT_FORK) || !ft_strcmp(error, MALLOC_THREAD)
		|| !ft_strcmp(error, INIT_THREAD))
		free(controllers->fork);
	if (!error || !ft_strcmp(error, INVALID_ARGS)
		|| !ft_strcmp(error, INIT_PRINT) || !ft_strcmp(error, MALLOC_FORK)
		|| !ft_strcmp(error, MALLOC_PHILO) || !ft_strcmp(error, INIT_FORK)
		|| !ft_strcmp(error, MALLOC_THREAD) || !ft_strcmp(error, INIT_THREAD))
		free(controllers);
	if (!error)
		return (EXIT_SUCCESS);
	return (error_message(error));
}
