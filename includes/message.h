/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:12:32 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/26 18:33:36 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_H
# define MESSAGE_H

/*
** Error codes for exit_program() function.
*/
# define MALLOC_CTRL		"failed at allocating memory - controllers.\n"
# define INVALID_ARGS		"invalid arguments.\n"
# define INIT_PRINT			"failed at initiating mutex - print.\n"
# define MALLOC_FORK		"failed at allocating memory - fork.\n"
# define MALLOC_PHILO		"failed at allocating memory - philosopher.\n"
# define INIT_FORK			"failed at initiating mutex - fork.\n"
# define MALLOC_THREAD		"failed at allocating memory - thread.\n"
# define INIT_THREAD		"failed at initializing thread.\n"

/*
** This typedef char * represents an error  The options for this type are the
** messages defined above.
*/
typedef char	*t_error;

/*
** Simulation messages for print_action() function.
*/
# define FORK				"has taken a fork"
# define EAT				"is eating"
# define SLEEP				"is sleeping"
# define THINK				"is thinking"
# define DIE				"died"

#endif /* MESSAGE_H */
