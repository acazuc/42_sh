/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:39:24 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/12 08:32:13 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_env	g_env;

void	sigint_handler(int signal)
{
	if (g_env.child_pid == 0)
	{
		ft_putchar('\n');
		print_line();
	}
	else
	{
		kill(g_env.child_pid, signal);
		g_env.child_pid = 0;
		ft_putchar('\n');
	}
}
