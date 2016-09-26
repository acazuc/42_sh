/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:54:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/26 15:46:49 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		print_error(char **args)
{
	ft_putstr_fd("cash: command not found: ", 2);
	ft_putendl_fd(args[0], 2);
}

static void		command_run_path(t_env *env, char **args)
{
	char		*tmp_command;
	char		**paths;
	char		*path;
	int			i;

	path = get_path(env);
	if (path)
	{
		if (!(paths = ft_strsplit(path, ':')))
			ERROR("Failed to malloc path");
		i = 0;
		while (paths[i])
		{
			tmp_command = ft_strjoin_free1(ft_strjoin_free1(paths[i], "/")
					, args[0]);
			if (!access(tmp_command, X_OK))
				execve(tmp_command, args, env->ev);
			i++;
		}
	}
	print_error(args);
}

static void		command_run_relative(t_env *env, char **args)
{
	if (!access(args[0], X_OK))
		execve(args[0], args, env->ev);
	print_error(args);
}

static void		do_run(t_env *env, char **args)
{
	pid_t		pid;

	pid = fork();
	if (pid == -1)
		ERROR("Failed to fork");
	else if (pid != 0)
		env_push_process(env, pid, args);
	else
	{
		if (ft_strchr(args[0], '/'))
			command_run_relative(env, args);
		else
			command_run_path(env, args);
		exit(0);
	}
}

void			command_run(t_env *env, char **args)
{
	if (args[0])
	{
		parse_command_vars(env, args);
		parse_command_tilde(env, args);
		parse_command_backslashs(args);
		parse_command_empty(&args);
		parse_command_unquote(args);
		if (!builtins(env, args))
		{
			do_run(env, args);
		}
	}
}
