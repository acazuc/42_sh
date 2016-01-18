/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 13:22:58 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/18 17:10:03 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_env	g_env;

static char	**dup_ev(char **ev)
{
	char	**new;
	int		len;

	len = 0;
	while (ev[len])
		len++;
	if (!(new = malloc(sizeof(*new) * (len + 1))))
		error_quit("Failed to malloc new env");
	len = 0;
	while (ev[len])
	{
		new[len] = ft_strdup(ev[len]);
		len++;
	}
	new[len] = NULL;
	return (new);
}

int			main(int ac, char **av, char **ev)
{
	pid_t		pid;
	char		*line;
	int			status;

	g_env.ev = dup_ev(ev);
	//signal(SIGINT, &sigint_handler);
	while (42)
	{
		print_line();
		get_next_line(1, &line);
		if (!parse_line(line))
			continue ;
		g_env.command.command = g_env.command.params[0];
		pid = fork();
		g_env.child_pid = pid;
		if (pid == 0)
		{
			command_run(&g_env.command);
			return (0);
		}
		wait(&status);
		g_env.child_pid = 0;
		signal_handler(status);
	}
	(void)ac;
	(void)av;
	return (0);
}
