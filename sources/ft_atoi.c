/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:24:59 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/26 17:36:55 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
int	ft_atoi(int *number, char *str, t_error *error)
{
	int	i;
	int	plus;

	i = 0;
	plus = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			*error = INVALID_ARGS;
		plus = 1;
	}
	i = plus;
	while (str[i])
		if (str[i] < '0' || str[i++] > '9')
			*error = INVALID_ARGS;
	if (*error)
		return (0);
	i = plus;
	*number = 0;
	while (str[i] >= '0' && str[i] <= '9')
		*number = (*number * 10) + (str[i++] - '0');
	if (*number == 0)
		*error = INVALID_ARGS;
	return (*number);
}
