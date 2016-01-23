/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_run_piped.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 10:51:26 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/23 11:09:24 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	command_run_piped(t_env *env, char **args, int pipe_type)
{
	pid_t	pid;
	int		status;
	int		*pipe_out;
	int		*pipe_in;

	pipe_out = env->which_pipe ? env->pipe_1 : env->pipe_2;
	pipe_in = env->which_pipe ? env->pipe_2 : env->pipe_1;
	pid = fork();
	if (pid == -1)
		error_quit("Failed to fork");
	else if (pid == 0)
	{
		if (pipe_type & PIPE_IN)
			dup2(pipe_in[0], 0);
		if (pipe_type & PIPE_OUT)
			dup2(pipe_out[1], 1);
		command_run(env, args);
		return ;
	}
	wait(&status);
	env->child_pid = 0;
	signal_handler(status);
	if (pipe_type & PIPE_OUT)
		close(pipe_out[1]);
	if (pipe_type & PIPE_IN)
	{
		close(pipe_in[0]);
		pipe(pipe_in);
	}
}
