/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:39:24 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/06 21:49:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_env	*g_env;

void	sigint_handler(int signal)
{
	t_process_list	*lst;

	lst = g_env->processes;
	if (!lst)
	{
		ft_putchar('\n');
		print_line(g_env);
		return ;
	}
	g_env->sigint = 1;
	while (lst)
	{
		kill(lst->process.pid, SIGKILL);
		lst = lst->next;
	}
	ft_putchar('\n');
	(void)signal;
}
