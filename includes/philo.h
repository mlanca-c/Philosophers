/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:25:56 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/07 16:06:40 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include "ansi.h"
# include "message.h"

/*
** Used in t_bool types.
*/
# define TRUE	1
# define FALSE	0

/*
** This typedef creates a specific type of integer number (int) called t_bool.
** This variable type will only have the values indicated by the macros TRUE and
** FALSE.
*/
typedef int				t_bool;

/*
** This typedef serves only as an abbreviation of the original pthread_mutex_t
** for t_mutex.
*/
typedef pthread_mutex_t	t_mutex;

/*
** This typedef serves only as an abbreviation of the original pthread_t for
** t_thread.
*/
typedef pthread_t		t_thread;

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
** This struct represents a fork. In the philosopher's dinner problem, each
** philosopher has a fork. And each philosopher needs two forks in order to eat
** from the bowl of spaghetti.
** Every fork will have:
** 		- name (int) : number ID of the fork.
** 		- used (t_bool) : boolean which will indicate if the fork's already taken
** 						by a philosopher.
** 		- mutex (t_mutex) : mutex to protect the fork from being taken more for
**						more than one philosopher.
*/
typedef struct s_fork
{
	int		name;
	t_bool	used;
	t_mutex	mutex;
}	t_fork;

/*
** This struct represents a philosopher. As such the struct contains the
** following attributes:
** 		- name (int) : number ID of the philosopher.
** 		- color (char *) : color of the philosopher - so that the output of the
** 						program is colored - ANSI_H.
** 		- thread (t_thread) : thread each philosopher represents.
** 		- status (t_status) : status of the philosopher.
** 		- times_philo_ate (int) : number of times a philosopher already ate from
** 								the bowl of spaghetti.
** 		- control (t_ctrl) : main program variable that contains all the
** 							program's information.
*/
typedef struct s_philosophers
{
	int					name;
	char				*color;
	t_thread			*thread;
	t_status			status;
	int					times_philo_ate;
	struct s_control	*control;
}	t_philo;

/*
** This is the main struct of the project. As such it contains the following
** variables:
** 		- nu_of_philo (int) : number of philosophers at the table.
** 		- time_to_die (int) : time a philosopher can go without eating.
** 		- time_to_eat (int) : time it takes for a philosopher to eat.
** 		- time_to_sleep (int) : time it takes for a philosopher to sleep.
** 		- nu_of_time_to_eat (int) : maximum number of times a philosopher needs
** 									to eat.
** 		- philosophers (t_philo *) : list of all the philosophers.
** 		- forks (t_forks *) : list of all the forks.
*/
typedef struct s_control
{
	int		nu_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nu_of_time_to_eat;
	t_philo	*philosophers;
	t_fork	*forks;
}	t_ctrl;

/*
**  libft Functions
*/
void	*ft_malloc(int size, void (*error_message)(char *));
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(const char *str);

/*
** command_utils.c Functions
*/
void	help_message(void);
void	error_message(char *message);
void	exit_program(t_ctrl *control);

/*
** control.c Functions
*/
t_ctrl	*init_control(int argc, char **argv);

/*
** forks.c Function
*/
t_fork	*init_forks(int number_of_forks);

/*
** philosophers.c Functions
*/
t_philo	*init_philosophers(t_ctrl *control);

#endif //PHILO_H
