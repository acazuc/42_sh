/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_run_piped.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 10:51:26 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/24 13:50:26 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		close_pipes(int pipe_type, int *pipe_in, int *pipe_out)
{
	if (pipe_type & PIPE_O)
		close(pipe_out[1]);
	else
	{
		close(pipe_out[0]);
		close(pipe_out[1]);
		pipe(pipe_out);
	}
	if (pipe_type & PIPE_I)
	{
		close(pipe_in[0]);
		pipe(pipe_in);
	}
}

static void		dup_pipes(int pipe_type, int *pipe_in, int *pipe_out)
{
	if (pipe_type & PIPE_I)
		dup2(pipe_in[0], 0);
	if (pipe_type & PIPE_O)
		dup2(pipe_out[1], 1);
}

void			command_run_piped(t_env *env, char **args, int pipe_type)
{
	pid_t	pid;
	int		status;
	int		*pipe_out;
	int		*pipe_in;

	pipe_out = env->which_pipe ? env->pipe_1 : env->pipe_2;
	pipe_in = env->which_pipe ? env->pipe_2 : env->pipe_1;
	env->which_pipe = !(env->which_pipe);
	pid = fork();
	if (pid == -1)
		error_quit("Failed to fork");
	else if (pid == 0)
	{
		dup_pipes(pipe_type, pipe_in, pipe_out);
		command_run(env, args);
		exit(1);
	}
	wait(&status);
	env->child_pid = 0;
	signal_handler(status);
	close_pipes(pipe_type, pipe_in, pipe_out);
}
