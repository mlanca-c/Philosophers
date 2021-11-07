/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ansi.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:55:59 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/07 16:09:15 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANSI_H
# define ANSI_H

/*
** Reset Color
*/
# define ANSI_RESET		"\033[0m"

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
** Foreground Colors
*/
# define ANSI_RED		"\033[31m"
# define ANSI_GREEN		"\033[32m"
# define ANSI_YELLOW	"\033[33m"
# define ANSI_BLUE		"\033[34m"
# define ANSI_MAGENTA	"\033[35m"
# define ANSI_CYAN		"\033[36m"
# define ANSI_WHITE		"\033[37m"

/*
** Background Colors
*/
# define ANSI_B_RED		"\033[41;1m"
# define ANSI_B_GREEN	"\033[42;1m"
# define ANSI_B_YELLOW	"\033[43;1m"
# define ANSI_B_BLUE	"\033[44;1m"
# define ANSI_B_MAGENTA	"\033[45;1m"
# define ANSI_B_CYAN	"\033[46;1m"
# define ANSI_B_WHITE	"\033[47;1m"

#endif //ANSI_H
