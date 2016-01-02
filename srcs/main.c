/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 13:22:58 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/02 17:25:18 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_command	g_command;

int		main(void)
{
	pid_t		pid;

	pid = 10;
	while (42)
	{
		if (pid == 0)
		{
			ft_putstr("Executing \'");
			ft_putstr(g_command.command);
			ft_putstr("\'\n");
			execve(g_command.command, g_command.params, g_command.env);
			return (0);
		}
		wait(&pid);
		ft_putstr("%> ");
		char	*mdr;
		get_next_line(1, &mdr);
		g_command.command = mdr;
		g_command.params = NULL;
		g_command.env = NULL;
		pid = fork();
	}
	return (0);
}
