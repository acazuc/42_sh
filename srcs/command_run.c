/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:54:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/11 08:27:22 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		command_run(t_command *command)
{
	char	*tmp_command;
	char	**paths;
	char	*path;
	int		i;

	path = getenv("PATH");
	if (!path)
		path = "/bin:/usr/bin";
	paths = ft_strsplit(path, ':');
	i = 0;
	while (paths[i])
	{
		tmp_command = ft_strjoin_free1(ft_strjoin(paths[i], "/"), command->command);
		execve(tmp_command, command->params, command->env);
		free(tmp_command);
		i++;
	}
	execve(command->command, command->params, command->env);
	return (0);
}
