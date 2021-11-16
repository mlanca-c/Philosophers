/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ansi.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:55:59 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/16 20:34:21 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANSI_H
# define ANSI_H

/*
** Reset Color
*/
# define ANSI_RESET		"\033[0m"

/*
** Simple Colors
*/
# define ANSI_RED		"\033[31m"
# define ANSI_GREEN		"\033[32m"
# define ANSI_YELLOW	"\033[33m"
# define ANSI_BLUE		"\033[34m"
# define ANSI_MAGENTA	"\033[35m"
# define ANSI_CYAN		"\033[36m"
# define ANSI_WHITE		"\033[37m"

/*
** Bold Colors
*/
# define ANSI_BRED		"\033[31;1m"
# define ANSI_BGREEN	"\033[32;1m"
# define ANSI_BYELLOW	"\033[33;1m"
# define ANSI_BBLUE		"\033[34;1m"
# define ANSI_BMAGENTA	"\033[35;1m"
# define ANSI_BCYAN		"\033[36;1m"
# define ANSI_BWHITE	"\033[37;1m"

/*
** This typedef creates a specific type of char * - string called t_color.
** This data type will represent only string values relative to colors -
** in this case, ansi color.
*/
typedef char	*t_color;

#endif /* ANSI_H */
