/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_run_piped.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 10:51:26 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/06 10:02:34 by acazuc           ###   ########.fr       */
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

static void		free_args(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

static void		init(t_env *env, char ***args, t_pipe_manager *m)
{
	m->pipe_out = env->which_pipe ? env->pipe_1 : env->pipe_2;
	m->pipe_in = env->which_pipe ? env->pipe_2 : env->pipe_1;
	env->which_pipe = !env->which_pipe;
	parse_command_vars(env, *args);
	parse_command_tilde(env, *args);
	parse_command_backslashs(*args);
	parse_command_empty(args);
	parse_command_unquote(*args);
}

void			command_run_piped(t_env *env, char **args, int pipe_type)
{
	t_pipe_manager	manager;
	pid_t			pid;
	int				status;

	init(env, &args, &manager);
	dup_pipes(pipe_type, &manager);
	if (!(builtins(env, args)))
	{
		pid = fork();
		if (pid == -1)
			ERROR("Failed to fork");
		else if (pid != 0)
			g_env->child_pid = pid;
		else if (pid == 0)
			command_run(env, args);
		wait(&status);
		env->child_pid = 0;
		signal_handler(status);
	}
	close_pipes(pipe_type, &manager);
	free_args(args);
}
