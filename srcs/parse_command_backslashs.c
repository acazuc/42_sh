/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_backslashs.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 08:24:15 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/03 11:32:23 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

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

static void	disassemble_assemble(t_parser_bs *p, char **arg)
{
	char	*sub_1;
	char	*sub_2;

	if (p->c != -129)
	{
		if (!(sub_1 = ft_strsub(*arg, 0, p->i)))
			ERROR("Failed to malloc backslash sub 1");
		if (!(sub_1 = ft_strjoin_free1(sub_1, (char*)(&p->c))))
			ERROR("Failed to malloc backslashs sub");
		if (!(sub_2 = ft_strsub(*arg, p->i + 2, ft_strlen(*arg) - p->i - 2)))
			ERROR("Failed to malloc backslash sub 2");
		free(*arg);
		if (!(*arg = ft_strjoin_free3(sub_1, sub_2)))
			ERROR("Failed to malloc backslash sub join");
	}
}

static void	check_quotes(t_parser_bs *p, char *arg)
{
	if (arg[p->i] == '\'' && !(p->in_dquote)
			&& (p->i == 0 || arg[p->i - 1] != '\\'))
		p->in_squote = !(p->in_squote);
	if (arg[p->i] == '"' && !(p->in_squote)
			&& (p->i == 0 || arg[p->i - 1] != '\\'))
		p->in_dquote = !(p->in_dquote);
}

static char	*parse_arg_backslashs(char *arg)
{
	t_parser_bs		p;

	p.in_squote = 0;
	p.in_dquote = 0;
	p.i = 0;
	while (arg[p.i])
	{
		check_quotes(&p, arg);
		if (arg[p.i] == '\\' && arg[p.i + 1])
		{
			p.c = -129;
			if ((p.in_squote || p.in_dquote)
					&& get_unescapable(arg[p.i]) != arg[p.i + 1])
				p.c = get_unescapable(arg[p.i + 1]);
			else if (!(p.in_squote) && !(p.in_dquote))
				p.c = arg[p.i + 1];
			disassemble_assemble(&p, &arg);
		}
		p.i++;
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
