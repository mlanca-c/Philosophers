/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:25:56 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/12 12:14:37 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include "ansi.h"
# include "message.h"

/*
** Used in t_bool types.
*/
# define TRUE	1
# define FALSE	0

/*
** This typedef creates a specific type of integer number (int) called t_bool.
** This data type will only have the values indicated by the macros TRUE and
** FALSE.
*/
typedef int				t_bool;

/*
** This typedef creates a specific type of integer number (int) called t_time.
** This data type will represent only integer values relative to time -
** in this case milliseconds.
*/
typedef long unsigned	t_time;

/*
** This enumeration has all the possible states a philosopher can have.
*/
typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	FINISHED
}	t_status;

/*
** This is the main struct of the project. As such it contains the following
** variables:
**		- start_time (t_time) : simulation start time.
** 		- nu_of_philo (int) : number of philosophers at the table.
** 		- time_to_die (int) : time a philosopher can go without eating.
** 		- time_to_eat (int) : time it takes for a philosopher to eat.
** 		- time_to_sleep (int) : time it takes for a philosopher to sleep.
** 		- nu_of_time_to_eat (int) : maximum number of times a philosopher needs
** 									to eat.
**		- threads (pthread_t *) : list of the project's threads.
**		- mutexes (pthread_mutex_t *) : list of the project's mutextes.
*/
typedef struct s_control
{
	int				start_time;
	int				nu_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nu_of_time_to_eat;
	pthread_t		*threads;
	pthread_mutex_t	*mutexes;
}	t_ctrl;

/*
** This struct represents a philosopher. As such the struct contains the
** following attributes:
** 		- id (int) : number ID of the philosopher.
** 		- color (char *) : color of the philosopher - so that the output of the
** 						program is colored - ANSI_H.
** 		- status (t_status) : status of the philosopher.
**		- last_ate (t_time) : time the philosopher ate last.
** 		- times_philo_ate (int) : number of times a philosopher already ate from
** 								the bowl of spaghetti.
**		- is_dead (t_bool) : indicates if the philosopher is dead.
** 		- control (t_ctrl) : main program variable that contains all the
** 							program's information.
*/
typedef struct s_philosopher
{
	int			id;
	char		*color;
	t_status	status;
	t_time		last_ate;
	int			times_philo_ate;
	t_bool		is_dead;
	t_ctrl		*control;
}	t_philo;

/*
**  libft Functions
*/
void	*ft_malloc(int size, void (*error_message)(char *));
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);

/*
** command_utils.c Functions
*/
void	help_message(void);
void	error_message(char *message);
void	exit_program(t_ctrl *control, int message);

/*
** control.c Function
*/
t_ctrl	*init_control(int argc, char **argv);

/*
** create_mutex.c Functions
*/
void	init_mutex(t_ctrl *control);
void	destroy_mutex(t_ctrl *control);

/*
** create_threads.c Functions
*/
void	malloc_threads(t_ctrl *control);
void	init_thread(t_ctrl *control, t_philo *philosopher);
void	destroy_threads(t_ctrl *control);

/*
** philosophers.c Function
*/
t_philo	*init_philosophers(t_ctrl *control);

/*
** get_time.c Function
*/
t_time	get_time(void);

// TESTING FUNCTION
void	*say_hello(void *philos);

#endif //PHILO_H
