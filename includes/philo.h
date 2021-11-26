/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:21:01 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/26 20:03:16 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdbool.h>
# include "color.h"
# include "message.h"

/*
** This typedef is an unsigned int that represents the milliseconds.
*/
typedef unsigned int	t_ms;

/*
** This is the controllers struct - the main structure of the project.
** The struct s_controllers contains all the important variables:
** 	- start_time (t_ms) : marks the simulation start time in milliseconds.
** 	- time_to_die (t_ms) : time in milliseconds it takes for a philosopher to
** 							die.
** 	- time_to_eat (t_ms) : time in milliseconds it takes for a philosopher to
** 							eat.
** 	- time_to_sleep (t_ms) : time in milliseconds it takes for a philosopher to
** 							sleep.
** 	- nu_philo (int) : number of philosophers in the simulation.
** 	- max_meal (int) : maximum number of times a philosopher needs to eat.
**	- death (bool) : boolean indicating if there's a dead philosopher.
** 	- philo (list t_philo) : list of philosophers.
** 	- fork (list t_fork) : list of forks.
** 	- thread (list pthread_t) : list of threads.
** 	- print (pthread_mutex_t) : protects status printed when a philosopher is
** 								printing an action so that it doesn't get
** 								scrambled with another philosopher's printing.
*/
typedef struct s_controllers
{
	t_ms			start_time;
	t_ms			time_to_die;
	t_ms			time_to_eat;
	t_ms			time_to_sleep;
	int				nu_philo;
	int				max_meal;
	bool			death;
	struct s_philo	*philo;
	struct s_fork	*fork;
	pthread_t		*thread;
	pthread_mutex_t	print;
}	t_ctrl;

/*
** This struct represents the fork each philosopher has by the table.
** The struct s_fork contains the following variables:
** 		- mutex (pthread_mutex_t) : mutex that protects the fork's status -
** 									when a philosopher grabs the fork,
** 									this mutex is locked not letting  other
** 									philosophers do the same.
** 		- used (bool) : boolean indicating if the fork is being used.
*/
typedef struct s_fork
{
	pthread_mutex_t	mutex;
	bool			used;
}	t_fork;

/*
** This struct represents a philosopher in the simulation.
** The struct s_philo contains the following variables:
** 		- id (int) : philosopher's identification number.
** 		- color (t_color) : color associated to the philosopher.
** 		- last_action (t_ms) : time of the last action the philosopher take.
** 		- last_meal (t_ms) : time of the last meal the philosopher take.
** 		- nu_meal (int) : number of meals the philosopher already take.
**		- fork (bool) : boolean indicating if the philosopher has both forks.
** 		- controllers (t_ctrl *) : controllers - struct t_ctrl * - variable.
*/
typedef struct s_philo
{
	int		id;
	t_color	color;
	t_ms	last_action;
	t_ms	last_meal;
	int		nu_meal;
	bool	fork;
	t_ctrl	*controllers;
}	t_philo;

/*
** command_utils.c Functions
*/
int		help_message(void);
int		error_message(char *message);
int		exit_program(t_ctrl *controllers, char *error);

/*
**  libft Functions
*/
void	*ft_malloc(int size, t_error *error, char *message);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(int *number, char *str, t_error *error);

/*
** controllers.c Function
*/
t_ctrl	*init_controllers(int argc, char *argv[], t_error *error);

/*
** fork.c Function
*/
t_fork	*init_fork(t_ctrl *controllers, t_error *error);

/*
** philo.c Function
*/
t_philo	*init_philo(t_ctrl *controllers, t_error *error);

/*
** time.c Functions
*/
t_ms	get_current_time(void);
t_ms	get_time(t_ms action);
void	ft_wait(t_ms time, t_philo *philo);

/*
** thread.c Functions
*/
void	init_thread(t_ctrl *controllers, t_error *error);
void	init_threads(t_ctrl *controllers, t_error *error);
void	join_threads(t_ctrl *controllers);

/*
** simulation.c Functions
*/
void	is_dead(t_philo *philo);
void	*simulation_one_phiosopher(void *args);
void	*simulation(void *args);

/*
** print_action.c Function
*/
void	print_action(char *action, t_philo *philo);
void	fprint_action(char *action, t_philo *philo, int fork);

/*
** actions.c Functions
*/
void	take_forks(t_philo *philo, int one, int two);
void	eat(t_philo *philo);
void	leave_forks(t_philo *philo, int one, int two);
void	sleep(t_philo *philo);

#endif /* PHILO_H */
