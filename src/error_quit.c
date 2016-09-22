/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 19:32:12 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 15:06:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	error_quit(char *error_message, char *file, int line)
{
	ft_putstr_fd("\033[1;31m", 2);
	ft_putstr_fd(error_message, 2);
	ft_putstr_fd(" (", 2);
	ft_putstr_fd(file, 2);
	ft_putchar_fd(':', 2);
	ft_putnbr_fd(line, 2);
	ft_putchar_fd(')', 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("\033[0;37m", 2);
	exit(EXIT_FAILURE);
}
