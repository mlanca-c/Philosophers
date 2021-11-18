/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:25:56 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/18 10:51:44 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include "ansi.h"
# include "message.h"

# define TRUE	1
# define FALSE	0

/*
** This typedef creates a specific type of integer number (int) called t_time.
** This data type will represent only integer values relative to time -
** in this case milliseconds.
*/
typedef long unsigned	t_time;

/*
** Thus struct represents the forks in the simulation. As such, it contains the
** following variables:
** 		- mutex_fork (pthread_mutex_t) : mutex for of fork in question.
** 		- philo_id (int) : id of the philosopher using the fork.
*/
typedef struct s_fork
{
	pthread_mutex_t	mutex_fork;
	int				philo_id;
}	t_fork;

/*
** This is the main struct of the project. As such it contains the following
** variables:
**		- start_time (t_time) : simulation start time.
** 		- time_to_die (t_time) : time a philosopher can go without eating.
** 		- time_to_eat (t_time) : time it takes for a philosopher to eat.
** 		- time_to_sleep (t_time) : time it takes for a philosopher to sleep.
** 		- nu_of_philo (int) : number of philosophers at the table.
** 		- nu_meals (int) : maximum number of times a philosopher needs
** 									to eat.
**		- deaths (int) : boolean that starts at FALSE and is TRUE when a
**		philosopher is dead.
**		- threads (pthread_t *) : list of the project's threads.
** 		- philos (t_philos *) : list of philosophers.
** 		- forks (t_forks *) : list of forks.
** 		- print (pthread_mutex_t) : mutex for the print_action().
** 		- dead (pthread_mutex_t) : mutex for the death of a philosopher.
*/
typedef struct s_control
{
	t_time			start_time;
	t_time			time_to_die;
	t_time			time_to_eat;
	t_time			time_to_sleep;
	int				nu_of_philo;
	int				nu_meals;
	int				deaths;
	pthread_t		*threads;
	struct s_philo	*philos;
	t_fork			*forks;
	pthread_mutex_t	*mutex_print;
	pthread_mutex_t	*mutex_dead;
}	t_ctrl;

/*
** This struct represents a philosopher. As such the struct contains the
** following attributes:
** 		- id (int) : number ID of the philosopher.
** 		- color (char *) : color of the philosopher - so that the output of the
** 						program is colored - ANSI_H.
** 		- meal_times (int) : number of times a philosopher already ate from the
** 								bowl of spaghetti.
**		- last_meal (t_time) : time the philosopher ate last.
** 		- last_action (t_time) : time of the last action the philosopher did.
** 		- control (t_ctrl) : main program variable that contains all the
** 							program's information.
*/
typedef struct s_philo
{
	int			id;
	t_color		color;
	int			meal_times;
	t_time		last_meal;
	t_time		last_action;
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
** fork.c Function
*/
void	init_forks(t_ctrl *control);

/*
** philosophers.c Functions
*/
void	init_philosopher(t_ctrl *control);
void	init_philosophers(t_ctrl *control);

/*
** create_mutex.c Functions
*/
void	init_mutex(t_ctrl *control);
void	destroy_mutex(t_ctrl *control);

/*
** create_threads.c Functions
*/
void	init_thread(t_ctrl *control);
void	destroy_threads(t_ctrl *control);

/*
** time.c Functions
*/
t_time	get_current_time(void);
t_time	get_time(t_time time);
void	ft_wait(t_time time, t_philo *philo);

/*
** simulation.c Functions
*/
void	*simulation_one_philosopher(void *arg);
void	*simulation(void *arg);
int		is_dead(t_philo *philo);

/*
** print_action.c Function
*/
void	print_action(char *message, t_philo *philo);

/*
** philo_actions.c Functions
*/
void	philo_take_forks(t_philo *philo, int right, int left);
void	philo_eat(t_philo *philo);
void	philo_leave_forks(t_philo *philo, int right, int left);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

#endif /* PHILO_H */
