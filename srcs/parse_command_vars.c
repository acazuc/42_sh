/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_vars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:26:55 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/06 11:43:17 by acazuc           ###   ########.fr       */
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
		if ((var[i] == '\'' || var[i] == '"' || var[i] == '$')
				&& (i == 0 || !(get_bs_nb_before(var, i) % 2)))
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

static char		*get_sub_2(t_env *env, char *arg, size_t i, size_t end)
{
	char	*sub2;
	char	*var;

	if (!(var = ft_strsub(arg, i, end - i + 1)))
		ERROR("Failed to get var type");
	if (!(sub2 = get_env_value(env, var)))
		sub2 = ft_strnew(0);
	free(var);
	return (unescape(sub2));
}

static char		*parse_arg_vars(t_env *env, char *arg)
{
	size_t		i;
	size_t		end;
	char		*sub1;
	char		*sub2;
	char		*sub3;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '$' && (i == 0 || !(get_bs_nb_before(arg, i) % 2))
				&& arg[i + 1] && !is_splitter(arg[i + 1]))
		{
			end = ++i;
			while (arg[end] && !is_splitter(arg[end]))
				end++;
			end--;
			sub2 = get_sub_2(env, arg, i, end);
			if (!(sub1 = ft_strsub(arg, 0, i - 1)))
				ERROR("Failed to get sub1");
			i += ft_strlen(sub2);
			if (!(sub3 = ft_strsub(arg + end + 1, 0, ft_strlen(arg))))
				ERROR("Failed to get sub3");
			free(arg);
			if (!(arg = ft_strjoin_free3(sub1, sub2))
					|| !(arg = ft_strjoin_free3(arg, sub3)))
				ERROR("Failed to join sub1, sub2 ans sub3");
		}
		i++;
	}
	return (arg);
}

void			parse_command_vars(t_env *env, char **cmd)
{
	size_t		i;

	i = 0;
	while (cmd[i])
	{
		cmd[i] = parse_arg_vars(env, cmd[i]);
		i++;
	}
}
