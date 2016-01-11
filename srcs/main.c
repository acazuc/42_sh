/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 13:22:58 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/11 09:57:27 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_env	g_env;

int		main(int ac, char **av, char **ev)
{
	pid_t		pid;
	char		*line;
	int			status;

	g_env.ev = ev;
	pid = 10;
	signal(SIGINT, &sigint_handler);
	while (42)
	{
		if (pid == 0)
		{
			command_run(&g_env.command);
			return (0);
		}
		wait(&status);
		g_env.child_pid = 0;
		signal_handler(status);
		print_line();
		get_next_line(1, &line);
		if (!parse_command(&(g_env.command), line))
			continue ;
		g_env.command.command = g_env.command.params[0];
		pid = fork();
		g_env.child_pid = pid;
	}
	(void)ac;
	(void)av;
	return (0);
}
