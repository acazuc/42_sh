/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_run_piped.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 10:51:26 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/16 10:01:35 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_env	*g_env;

static void		close_pipes(int pipe_type, t_pipe_manager *m)
{
	if (pipe_type & PIPE_O)
	{
		close(m->pipe_out[1]);
		dup2(m->origin_stdout, 1);
		close(m->origin_stdout);
	}
	else
	{
		close(m->pipe_out[0]);
		close(m->pipe_out[1]);
		pipe(m->pipe_out);
	}
	if (pipe_type & PIPE_I)
	{
		close(m->pipe_in[0]);
		dup2(m->origin_stdin, 0);
		close(m->origin_stdin);
		pipe(m->pipe_in);
	}
}

static void		dup_pipes(int pipe_type, t_pipe_manager *m)
{
	if (pipe_type & PIPE_I)
	{
		m->origin_stdin = dup(0);
		close(0);
		dup2(m->pipe_in[0], 0);
	}
	if (pipe_type & PIPE_O)
	{
		m->origin_stdout = dup(1);
		close(1);
		dup2(m->pipe_out[1], 1);
	}
}

void			command_run_piped(t_env *env, char **args, int pipe_type)
{
	t_pipe_manager	manager;

	manager.pipe_out = env->which_pipe ? env->pipe_1 : env->pipe_2;
	manager.pipe_in = env->which_pipe ? env->pipe_2 : env->pipe_1;
	env->which_pipe = !env->which_pipe;
	dup_pipes(pipe_type, &manager);
	command_split_redirs(env, args);
	close_pipes(pipe_type, &manager);
}
