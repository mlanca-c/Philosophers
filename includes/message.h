/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:52:39 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/16 23:48:24 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_H
# define MESSAGE_H

/*
** Error codes for exit_program() function.
*/
# define NO_ERRORS			0
# define ERROR_MUTEX		1
# define ERROR_THREAD		2

/*
** Error messages for error_message() function.
*/
# define INVALID_ARGS_NUM	"invalid arguments, wrong number of arguments\n"
# define INVALID_ARGS_MINUS	"invalid arguments, using negative numbers.\n"
# define INVALID_ARGS_ALPHA	"invalid arguments, using non-integers arguments.\n"
# define WRONG_PHILO_NU		"invalid argumenst, wrong number of philosophers.\n"
# define MALLOC_ERROR		"failed at allocating memory.\n"
# define MUTEX_ERROR		"failed at creating new mutex.\n"
# define THREAD_ERROR		"failed at creating new thread.\n"

/*
** Simulation messages
*/
# define FORK				"has taken a fork\t|\n"
# define EAT				"is eating\t\t|\n"
# define SLEEP				"is sleeping\t\t|\n"
# define THINK				"is thinking\t\t|\n"
# define DIE				"died\t\t\t|\n"

#endif /* MESSAGE_H */
