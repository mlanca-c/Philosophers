/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:23:52 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/26 16:52:32 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** This function allocates the necessary memory space ('size') for 'aloc'. If
** the allocation fails the function error_message() is called. Else 'aloc' is
** returned.
**
** @param	int	size	- size of memory needed for the malloc() function.
**
** @returns
** 	void pointer with the allocated memory, if successful. In case of error the
** 	error_message() function is called and the program exits with EXIT_FAILURE.
*/
void	*ft_malloc(int size, t_error *error, char *message)
{
	void	*alloc;

	alloc = malloc(size);
	if (!alloc)
		*error = message;
	return (alloc);
}
