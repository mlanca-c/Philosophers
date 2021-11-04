/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:15:53 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/04 20:35:32 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
*/
void	help_message(void)
{
	printf("[ format ]: ");
	printf("./philo <num_philo> <time_to_die> <time_to_eat> ");
	printf("<time_to_sleep> [num_times_each_philo_must_eat]\n\n");
	printf("\t* num_philo: number of philosophers (mandatory).\n");
	printf("\t* time_to_die: time a philosopher can go without eating\n");
	printf("\t\tcounted from the moment he started eating (mandatory).\n");
	printf("\t* time_to_eat: (mandatory)\n");
	printf("\t* time_to_sleep: (mandatory)\n");
	printf("\t* num_times_each_philo_must_eat: (optional)\n");
	exit(EXIT_SUCCESS);
}

/*
*/
void	error_message(char *message)
{
	printf("[ philosophers ]: %s", message);
	printf("[ correct format ]:\n");
	printf("\t./philo <num_philo> <time_to_die> <time_to_eat> ");
	printf("<time_to_sleep> [num_times_each_philo_must_eat]\n");
	printf("\n\tadditional info: ./philo --help\n");
	exit(EXIT_FAILURE);
}
