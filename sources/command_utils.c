/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:46:19 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/12/03 11:20:19 by mlanca-c         ###   ########.fr       */
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
** This function is called by the exit_program() function, after freeing
** everything, in case of error. The error_message() function displays an error
** message - 'error' and then returns to the main() function EXIT_FAILURE.
**
** If so, the error_message() function displays an error message, and exits the
** program with EXIT_FAILURE.
** This function takes no arguments and ends the program when called.
**
** @param	char	*error	- message to be displayed to the user.
*/
int	error_message(char *error)
{
	printf("\n[ " RED "philosophers" RESET " ]: %s", error);
	if (!ft_strcmp(error, INVALID_ARGS))
		printf("[ "RED "info" RESET " ]: ./philo --help\n");
	return (EXIT_FAILURE);
}

/*
** This function is called by the exit_program() function once the program has
** no errors and is freeing and destroying all variables.
** The destroy_mutex() function destroys the all the struct s_fork mutex
** variable - t_fork->mutex - and the struct s_controllers controllers->print
** mutex as well.
**
** @param	t_ctrl	*controllers	- main struct  of the program. It contains
** 									all important variables of the project.
*/
void	destroy_mutex(t_ctrl *controllers)
{
	int	i;

	i = 0;
	while (i < controllers->nu_philo)
		pthread_mutex_destroy(&(controllers->fork[i++].mutex));
	pthread_mutex_destroy(&(controllers->print));
}

/*
** This function is called once the simulation ends - either a philosopher dies
** or every philosopher ate the maximum amount of times it could - or in case of
** error such as malloc failures, thread and mutex error.
** The function frees all allocated memory based on the 'error'.
**
** @param	t_ctrl	*controllers	- main variable of the program that at the
** 									end of the function should be all freed.
** @param	char	*error			- t_error type of variable that represents
** 									all possible errors the program can have.
**
** @return
** 		- the exit_program() function returns EXIT_SUCCESS, if the program has
** 		no errors. In case of failure, the function calls error_message() to
** 		display an error message and return EXIT_FAILURE.
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
	{
		destroy_mutex(controllers);
		free(controllers->fork);
	}
	if (!error || !ft_strcmp(error, INVALID_ARGS)
		|| !ft_strcmp(error, INIT_PRINT) || !ft_strcmp(error, MALLOC_FORK)
		|| !ft_strcmp(error, MALLOC_PHILO) || !ft_strcmp(error, INIT_FORK)
		|| !ft_strcmp(error, MALLOC_THREAD) || !ft_strcmp(error, INIT_THREAD))
		free(controllers);
	if (!error)
		return (EXIT_SUCCESS);
	return (error_message(error));
}
