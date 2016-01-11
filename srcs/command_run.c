/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:54:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/11 10:13:25 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_env			g_env;

static void		print_error()
{
	if (g_env.command.command)
	{
		ft_putstr(g_env.command.command);
		ft_putendl(": command not found");
	}
}

void			command_run(t_command *command)
{
	char	*tmp_command;
	char	**paths;
	char	*path;
	int		i;

	path = get_path();
	if (path)
	{
	paths = ft_strsplit(path, ':');
		i = 0;
		while (paths[i])
		{
			tmp_command = ft_strjoin_free1(ft_strjoin_free1(paths[i], "/"), command->command);
			execve(tmp_command, command->params, g_env.ev);
			free(tmp_command);
			i++;
		}
	}
	execve(command->command, command->params, g_env.ev);
	print_error();
}
