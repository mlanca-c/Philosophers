/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:24:59 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/25 17:20:06 by mlanca-c         ###   ########.fr       */
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
int	ft_atoi(char *str)
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
	if (number == 0)
		error_message(INVALID_ARGS_ZERO);
	return (number);
}
