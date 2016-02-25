/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_backslashs.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 08:24:15 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/25 11:45:46 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	is_unescapable(char c)
{
	return (c == 'a' || c == 'b' || c == 'e' || c == 'E' || c == 'f'
			|| c == 'n' || c == 'r' || c == 't' || c == 'v');
}

static char	get_unescapable(char c)
{
	if (c == 'a')
		return ('\a');
	if (c == 'b')
		return ('\b');
	if (c == 'e' || c == 'E')
		return ('\033');
	if (c == 'f')
		return ('\f');
	if (c == 'n')
		return ('\n');
	if (c == 'r')
		return ('\r');
	if (c == 't')
		return ('\t');
	if (c == 'v')
		return ('\v');
	return (c);
}

static char	*parse_arg_backslashs(char *arg)
{
	char	*sub_1;
	char	*sub_2;
	int		c;
	int		in_squote;
	int		in_dquote;
	int		i;

	in_squote = 0;
	in_dquote = 0;
	i = 0;
	while (arg[i])
	{
		if (arg[i] == '\'' && !in_dquote && (i == 0 || arg[i - 1] != '\\'))
			in_squote = !in_squote;
		if (arg[i] == '"' && !in_squote && (i == 0 || arg[i - 1] != '\\'))
			in_dquote = !in_dquote;
		if (arg[i] == '\\' && arg[i + 1])
		{
			c = -129;
			if ((in_squote || in_dquote) && is_unescapable(arg[i + 1]))
				c = get_unescapable(arg[i + 1]);
			else if (!in_squote && !in_dquote)
				c = arg[i + 1];
			if (c != -129)
			{
				if (!(sub_1 = ft_strsub(arg, 0, i)))
					error_quit("Failed to malloc backslash sub 1");
				if (!(sub_1 = ft_strjoin_free1(sub_1, (char*)(&c))))
					error_quit("Failed to malloc backslashs sub");
				if (!(sub_2 = ft_strsub(arg, i + 2, ft_strlen(arg) - i - 2)))
					error_quit("Failed to malloc backslash sub 2");
				free(arg);
				if (!(arg = ft_strjoin_free3(sub_1, sub_2)))
					error_quit("Failed to malloc backslash sub join");
			}
		}
		i++;
	}
	return (arg);
}

void		parse_command_backslashs(char **cmd)
{
	size_t	i;

	i = 0;
	while (cmd[i])
	{
		cmd[i] = parse_arg_backslashs(cmd[i]);
		i++;
	}
}
