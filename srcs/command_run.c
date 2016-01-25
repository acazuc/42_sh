/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:54:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/25 08:24:38 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		print_error(char **args)
{
	ft_putstr(args[0]);
	ft_putendl(": command not found");
}

static void		command_run_path(t_env *env, char **args)
{
	char	*tmp_command;
	char	**paths;
	char	*path;
	int		i;

	path = get_path(env);
	if (path)
	{
		paths = ft_strsplit(path, ':');
		i = 0;
		while (paths[i])
		{
			tmp_command = ft_strjoin_free1(ft_strjoin_free1(paths[i], "/")
					, args[0]);
			if (!access(tmp_command, F_OK))
				execve(tmp_command, args, env->ev);
			free(tmp_command);
			i++;
		}
	}
	print_error(args);
}

static void		command_run_relative(t_env *env, char **args)
{
	if (!access(args[0], F_OK))
		execve(args[0], args, env->ev);
	print_error(args);
}

void			command_run(t_env *env, char **args)
{
	int		i;

	if (args[0])
	{
		i = 1;
		while (args[i])
		{
			args[i] = replace_tilde_home(env, args[i]);
			args[i] = param_remove_quotes(args[i]);
			args[i] = param_remove_backslashs(args[i]);
			i++;
		}
		if (!builtins(env, args))
		{
			if (ft_strchr(args[0], '/'))
				command_run_relative(env, args);
			else
				command_run_path(env, args);
		}
	}
}
