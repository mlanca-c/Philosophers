/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:23:52 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/26 23:30:26 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** This function allocates the necessary memory space ('size') for 'aloc'. If
** the allocation fails the function error_message() is called. Else 'aloc' is
** returned.
**
** @param	int	size	- size of memory needed for the malloc() function.
** @param	t_error	*error	- variable address of an error - typedef char *.
** 							In case of error, this variable will stop being null
** 							and the function will end. The exit_program()
** 							function will then be called and 'error' will be
** 							displayed in the command line.
** @param	char	*message	- message 'error' will contain in case of malloc
**								failure.
**
** @returns
** 	void pointer with the allocated memory, if successful. In case of error the
** 	'error' variable is set to message.
*/
void	*ft_malloc(int size, t_error *error, char *message)
{
	void	*alloc;

	alloc = malloc(size);
	if (!alloc)
		*error = message;
	return (alloc);
}
