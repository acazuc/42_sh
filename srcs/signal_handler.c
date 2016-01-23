/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 17:23:35 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/23 11:41:02 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	signal_handler(int status)
{
	int		signal;

	if (WIFSIGNALED(status))
	{
		signal = WTERMSIG(status);
		if (signal == SIGSEGV)
			ft_putendl("Segfault happened");
		else if (signal == SIGFPE)
			ft_putendl("Floating point exception");
		else if (signal == SIGILL)
			ft_putendl("Illegal operation");
		else if (signal == SIGBUS)
			ft_putendl("Bus error");
	}
}
