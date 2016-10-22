/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_run_piped.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 10:51:26 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/22 14:23:17 by acazuc           ###   ########.fr       */
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
		if (pipe(m->pipe_out))
			ERROR("Failed to pipe");
	}
	if (pipe_type & PIPE_I)
	{
		close(m->pipe_in[0]);
		dup2(m->origin_stdin, 0);
		close(m->origin_stdin);
		if (pipe(m->pipe_in) == -1)
			ERROR("Failed to pipe");
	}
}

static void		dup_pipes(int pipe_type, t_pipe_manager *m)
{
	if (pipe_type & PIPE_I)
	{
		if ((m->origin_stdin = dup(0)) == -1)
			ERROR("Failed to dup");
		close(0);
		if (dup2(m->pipe_in[0], 0) == -1)
			ERROR("Failed to dup2");
	}
	if (pipe_type & PIPE_O)
	{
		if ((m->origin_stdout = dup(1)) == -1)
			ERROR("Failed to dup");
		close(1);
		if (dup2(m->pipe_out[1], 1) == -1)
			ERROR("Failed to dup2");
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
