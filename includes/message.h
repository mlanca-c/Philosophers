/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:12:32 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/24 15:16:10 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_H
# define MESSAGE_H

/*
** Error codes for exit_program() function.
*/
# define NO_ERROR			0
# define EXIT_MUTEX			1
# define EXIT_THREAD		2

/*
** Error messages for error_message() function.
*/
# define MALLOC_ERROR		"failed at allocating memory.\n"
# define INVALID_ARGS_NUM	"invalid arguments, wrong number of arguments\n"
# define INVALID_ARGS_MINUS	"invalid arguments, using negative numbers.\n"
# define INVALID_ARGS_ALPHA	"invalid arguments, using non-integers arguments.\n"
# define NO_PHILO			"invalid arguments, zero philosophers.\n"
# define TOO_MANY_PHILO		"invalid arguments, too many philosophers.\n"

//# define MUTEX_ERROR		"failed at creating new mutex.\n"
//# define THREAD_ERROR		"failed at creating new thread.\n"

/*
** Simulation messages for print_action() function.
*/
# define FORK				"has taken a fork."
# define EAT				"is eating."
# define SLEEP				"is sleeping."
# define THINK				"is thinking."
# define DIE				"died."

#endif /* MESSAGE_H */
