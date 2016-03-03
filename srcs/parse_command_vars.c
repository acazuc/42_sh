/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_vars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:26:55 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/03 13:58:38 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char		*unescape(char *var)
{
	size_t	i;
	char	*tmp1;
	char	*tmp2;

	i = 0;
	while (var[i])
	{
		if ((var[i] == '\'' || var[i] == '"') && (i == 0 || var[i - 1] != '\\'))
		{
			if (!(tmp1 = ft_strsub(var, 0, i)))
				ERROR("Failed to sub");
			if (!(tmp1 = ft_strjoin_free1(tmp1, "\\")))
				ERROR("Failed to join");
			if (!(tmp2 = ft_strsub(var, i, ft_strlen(var) - i)))
				ERROR("Failed to sub");
			free(var);
			if (!(var = ft_strjoin_free3(tmp1, tmp2)))
				ERROR("Failed to sub");
		}
		i++;
	}
	return (var);
}

static int		is_splitter(char c)
{
	return (c == ' ' || c == '|' || c == ';' || c == '\t' || c == '\\'
			|| c == '\'' || c == '"');
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
			end--;
			if (!(var = ft_strsub(arg, i, end - i + 1)))
				ERROR("Failed to get var type");
			if (!(sub2 = get_env_value(env, var)))
				sub2 = ft_strnew(0);
			sub2 = unescape(sub2);
			if (!(sub1 = ft_strsub(arg, 0, i - 1)))
				ERROR("Failed to get sub1");
			if (!(sub3 = ft_strsub(arg, i + ft_strlen(var), ft_strlen(arg) - i - ft_strlen(var))))
				ERROR("Failed to get sub3");;
			i = i + ft_strlen(sub2);
			free(var);
			if (!(arg = ft_strjoin_free3(sub1, sub2)))
				ERROR("Failed to join sub1 and sub2");
			if (!(arg = ft_strjoin_free3(arg, sub3)))
				ERROR("Failed to join sub2 ans sub3");
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
