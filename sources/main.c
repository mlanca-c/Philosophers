/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:38:41 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/05 20:14:47 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
*/
int	main(int argc, char *argv[])
{
	t_ctrl	*control;

	if (argc > 1 && !ft_strcmp(argv[1], "--help"))
		help_message();
	else if (argc != 5 && argc != 6)
		error_message(INVALID_ARGS_NUM);
	control = init_control(argc, argv);
	exit_program(control);
	return (0);
}
