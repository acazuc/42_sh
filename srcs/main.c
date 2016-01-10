/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 13:22:58 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/10 17:18:38 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_command	g_command;

int		main(void)
{
	pid_t		pid;
	char		*line;
	int			status;

	pid = 10;
	signal(SIGINT, &sigint_handler);
	while (42)
	{
		if (pid == 0)
		{
			if (!command_run(&g_command))
			{
				if (g_command.command)
				{
					ft_putstr("cash: ");
					ft_putstr(g_command.command);
					ft_putendl(": command not found");
				}
			}
			return (0);
		}
		wait(&status);
		signal_handler(status);
		print_line();
		get_next_line(1, &line);
		if (!parse_command(&g_command, line))
			continue ;
		g_command.command = g_command.params[0];
		g_command.env = NULL;
		pid = fork();
	}
	return (0);
}
