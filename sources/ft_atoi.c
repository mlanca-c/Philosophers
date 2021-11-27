/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:24:59 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/26 23:29:12 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** This function converts a ASCII string to an integer.
** The ft_atoi() function converts the initial portion of the string pointed to
** by str to int representation.
**
** @param	const char	*str	- string to be converted to int.
** @param	int			*number	- integer resuling in the conversion of 'str'.
** @param	t_error	*error	- variable address of an error - typedef char *.
** 							In case of error, this variable will stop being null
** 							and the function will end. The exit_program()
** 							function will then be called and 'error' will be
** 							displayed in the command line.
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
