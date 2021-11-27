/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:12:59 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/11/26 22:22:27 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

/*
** Reset Color
*/
# define RESET		"\033[0m"

# define FRED		"\033[41m"

/*
** Simple Colors
*/
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

/*
** Bold Colors
*/
# define BRED		"\033[31;1m"
# define BGREEN		"\033[32;1m"
# define BYELLOW	"\033[33;1m"
# define BBLUE		"\033[34;1m"
# define BMAGENTA	"\033[35;1m"
# define BCYAN		"\033[36;1m"
# define BWHITE		"\033[37;1m"

/*
** This typedef char * represents a color. The options for this type are the
** colors defined above.
*/
typedef char	*t_color;

#endif /* COLOR_H */
