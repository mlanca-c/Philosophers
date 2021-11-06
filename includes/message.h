/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:52:39 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/06 19:43:25 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_H
# define MESSAGE_H

/*
** Error messages
*/
# define MALLOC_ERROR		"failed at allocating memory.\n"
# define INVALID_ARGS_NUM	"invalid arguments, wrong number of arguments\n"
# define INVALID_ARGS_MINUS	"invalid arguments, using negative numbers.\n"
# define INVALID_ARGS_ALPHA	"invalid arguments, using non-integers arguments.\n"
# define MUTEX_ERROR		"failed at creating new mutex.\n"
# define THREAD_ERROR		"failed at creating new thread.\n"

/*
** Simulation messages
*/
# define FORK				"has taken a fork\n"
# define EAT				"is eating\n"
# define SLEEP				"is sleeping\n"
# define THINK				"is thinking\n"
# define DIE				"died\n"

#endif //MESSAGE_H
