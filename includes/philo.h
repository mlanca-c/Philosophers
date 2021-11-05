/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:25:56 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/05 20:08:39 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "ansi.h"
# include "message.h"

/*
*/
typedef enum e_bool
{
	TRUE,
	FALSE
}	t_bool;

/*
*/
typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	FINISHED
}	t_status;

/*
*/
typedef struct s_fork
{
	int				philo_name;
	bool			used;
	pthread_mutex_t	mutex;
}	t_fork;

/*
*/
typedef struct s_philo
{
	int					name;
	t_status			status;
	pthread_t			thread;
	t_fork				right_fork;
	t_fork				left_fork;
	int					times_philo_ate;
	struct s_control	*control;
}	t_philo;

/*
*/
typedef struct s_control
{
	int		nu_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nu_of_time_to_eat;
	t_philo	*philos;
	t_fork	*forks;
}	t_ctrl;

/*
** command_utils.c Functions
*/
void	help_message(void);
void	error_message(char *message);
void	exit_program(t_ctrl *control);

/*
**  mini_libft.c Functions
*/
void	*ft_malloc(int size, void (*error_message)(char *));
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(const char *str);

/*
** control.c Functions
*/
t_ctrl	*init_control(int argc, char **argv);

#endif //PHILO_H
