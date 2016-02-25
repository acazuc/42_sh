/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_vars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:26:55 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/25 16:54:14 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int		is_splitter(char c)
{
	return (c == ' ' || c == '|' || c == ';' || c == '\t' || c == '\\');
}

static char		*parse_arg_vars(t_env *env, char *arg)
{
	size_t		i;
	size_t		end;
	char		*var;
	char		*sub1;
	char		*sub2;
	char		*sub3;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '$' && (i == 0 || arg[i - 1] != '\\') && !is_splitter(arg[i + 1]))
		{
			end = ++i;
			while (arg[end] && !is_splitter(arg[end]))
				end++;
			if (!(var = ft_strsub(arg, i, end - i + 1)))
				error_quit("Failed to get var type parse_arg_vars");
			if (!(sub2 = get_env_value(env, var)))
				sub2 = ft_strnew(0);
			if (!(sub1 = ft_strsub(arg, 0, i - 1)))
				error_quit("Failed to get sub1");
			if (!(sub3 = ft_strsub(arg, i + ft_strlen(var), ft_strlen(arg) - i - ft_strlen(var))))
				error_quit("Failed to get sub3");
			free(var);
			if (!(arg = ft_strjoin_free1(sub1, sub2)))
				error_quit("Failed to join sub1 and sub2");
			if (!(arg = ft_strjoin_free3(arg, sub3)))
				error_quit("Failed to join sub2 ans sub3");
			i = i + ft_strlen(sub2);
			free(sub2);
		}
		i++;
	}
	return (arg);
}

void		parse_command_vars(t_env *env, char **cmd)
{
	size_t		i;

	i = 0;
	while (cmd[i])
	{
		cmd[i] = parse_arg_vars(env, cmd[i]);
		i++;
	}
}
