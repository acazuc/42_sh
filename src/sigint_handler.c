/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:39:24 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/26 15:56:45 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_env	*g_env;

void	sigint_handler(int signal)
{
	/*if (g_env->child_pid)
	{
		kill(g_env->child_pid, SIGKILL);
		ft_putchar('\n');
		g_env->child_pid = 0;
	}
	else
	{
		ft_putchar('\n');
		print_line(g_env);
	}*/
	(void)signal;
}
