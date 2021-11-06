/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:24:38 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/06 18:24:47 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
