/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_vars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:26:55 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/06 12:51:45 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

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
	return (parse_command_unescape(sub2));
}

static void		through_var(char *arg, size_t *i, size_t *end)
{
	*end = ++(*i);
	while (arg[*end] && !is_splitter(arg[*end]))
		(*end)++;
	(*end)--;
}

static char		*parse_arg_vars(t_env *env, char *arg)
{
	size_t		end;
	size_t		i;
	char		*sub2;
	char		*result;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '$' && (i == 0 || !(get_bs_nb_before(arg, i) % 2))
				&& arg[i + 1] && !is_splitter(arg[i + 1]))
		{
			through_var(arg, &i, &end);
			sub2 = get_sub_2(env, arg, i, end);
			if (!(result = ft_strnew(ft_strlen(arg) - (end - i + 1) +
							ft_strlen(sub2))))
				ERROR("Failed to malloc new result");
			result = ft_strncat(result, arg, i - 1);
			result = ft_strcat(result, sub2);
			result = ft_strcat(result, arg + end + 1);
			free(arg);
			arg = result;
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
