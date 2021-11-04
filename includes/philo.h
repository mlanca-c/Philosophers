/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:25:56 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/04 20:35:47 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "message.h"

/*
*/
typedef enum e_state
{
	EATING,
	SLEEPING,
	THINKING,
	FINISHED
}	t_state;

typedef struct s_fork
{
	int				philo_name;
	bool			used;
	pthread_mutex_t mutex;

} t_fork;

/*
*/
typedef struct s_philo
{
	int					name;
	t_state				state;
	//pthread_t			thread;
	//t_fork			right_fork;
	//t_fork			left_fork;
	int					times_philo_ate;
	struct s_control	*control;
}	t_philo;

/*
*/
typedef struct s_control
{
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		time_to_eat_num;
	t_philo *philos;
} t_ctrl;

/*
*/ 
void	help_message(void);
void	error_message(char *message);

/*
*/ 
void	*ft_malloc(int size, void (*error_message)(char *));
int		ft_strcmp(char *s1, char *s2);

#endif //PHILO_H
