/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:38:41 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/04 20:13:35 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
*/
int	main(int argc, char *argv[])
{
	if (argc > 1 && !ft_strcmp(argv[1], "--help"))
		help_message();
	else if (argc < 5)
		error_message(INVALID_ARGS);
	return (0);
}
