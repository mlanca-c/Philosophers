/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:40:30 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/05 20:08:59 by mlanca-c         ###   ########.fr       */
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
void	*ft_malloc(int size, void (*error_message)(char *))
{
	void	*alloc;

	alloc = malloc(size);
	if (!alloc)
		error_message(MALLOC_ERROR);
	return (alloc);
}

/*
** This function compares two strings.
** The ft_strcmp() function compares the string pointed to, by 'str1' to the
** string pointed to by 'str2'.
**
** @param	char	*str1	- The first string to be compared.
** @param	char	*str2	- The second string to be compared.
**
** @return
** 		- The ft_strcmp() returns < 0 if str1 is less than str 2; < 0 if the
** 		opposite occurs; and 0 if the strings are equal to one another.
*/
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2++)
		if (*s1++ == 0)
			return (0);
	return (*s1 - *--s2);
}

/*
** This function converts a ASCII string to an integer.
** The ft_atoi() function converts the initial portion of the string pointed to
** by str to int representation.
**
** @param	const char	*str	- string to be converted to int.
**
** @return
** 		- The ft_atoi() function returns the int representation of the string.
*/
int	ft_atoi(const char *str)
{
	int	i;
	int	plus;
	int	number;

	i = 0;
	plus = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			error_message(INVALID_ARGS_MINUS);
		plus = 1;
	}
	while (str[i])
		if (str[i] < '0' || str[i++] > '9')
			error_message(INVALID_ARGS_ALPHA);
	i = plus;
	number = 0;
	while (str[i] >= '0' && str[i] <= '9')
		number = (number * 10) + (str[i++] - '0');
	return (number);
}
