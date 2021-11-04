/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:40:30 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/04 20:16:19 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
*/
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2++)
		if (*s1++ == 0)
			return (0);
	return (*s1 - *--s2);
}

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
void	*ft_malloc(int size, void (*error_message)(char *))
{
	void	*alloc;

	alloc = malloc(size);
	if (!alloc)
		error_message(MALLOC_ERROR);
	return (alloc);
}
