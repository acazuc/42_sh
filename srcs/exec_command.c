/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 09:49:09 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/23 09:57:14 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	exec_command(t_env *env, t_command *command)
{
	t_pid	pid;
	int		status;

	pid = fork();
	if (pid == -1)
	{
		error_quit("Failed to fork");	
	}
	else if (pid == 0)
	{
		command_run(command);
		return ;
	}
	else
	{
		wait(&status);
		env->child_pid = 0;
		signal_handler(status);
	}
}
