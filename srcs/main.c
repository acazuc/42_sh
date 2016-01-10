/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 13:22:58 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/10 16:33:37 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_command	g_command;

int		main(void)
{
	pid_t		pid;
	char		*cwd;
	char		*line;
	int			status;

	pid = 10;
	cwd = malloc(sizeof(*cwd) * 10000);
	while (42)
	{
		if (pid == 0)
		{
			if (execve(g_command.command, g_command.params, g_command.env) == -1)
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
		/*cwd = getcwd(cwd, 10000);
		ft_putstr("\e[1;37m[");
		ft_putstr(getenv("USER"));
		ft_putstr("] \e[0;32m");
		ft_putstr(cwd);
		ft_putstr("\e[1;37m $ \e[0;37m");*/
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
