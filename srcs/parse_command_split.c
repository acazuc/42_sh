/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_split.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 10:47:55 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/03 11:34:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		check_quotes(t_parser *p)
{
	if (p->cmd[p->i] == '\'' && !(p->in_dquote)
			&& (p->i == 0 || p->cmd[p->i - 1] != '\\'))
		p->in_squote = !(p->in_squote);
	if (p->cmd[p->i] == '"' && !(p->in_squote)
			&& (p->i == 0 || p->cmd[p->i - 1] != '\\'))
		p->in_dquote = !(p->in_dquote);
}

static void		add_next_arg(t_parser *p)
{
	while (p->cmd[p->i] && (p->in_squote || p->in_dquote
				|| (p->cmd[p->i] != ' ' && p->cmd[p->i] != '\t')))
	{
		check_quotes(p);
		if (!p->in_squote && !p->in_dquote)
		{
			if (p->cmd[p->i] == '|' || p->cmd[p->i] == ';')
			{
				if (p->i != p->start)
					parse_command_push_param(p);
				p->start = p->i++;
				parse_command_push_param(p);
				p->start = p->i;
				return ;
			}
		}
		p->i++;
	}
}

static void		init(t_parser *p, char *cmd)
{
	if (!(p->result = malloc(sizeof(*p->result))))
		ERROR("Failed to malloc splitter result");
	p->result[0] = NULL;
	p->cmd = cmd;
	p->in_dquote = 0;
	p->in_squote = 0;
	p->i = 0;
}

char			**parse_command_split(char *cmd)
{
	t_parser	p;

	init(&p, cmd);
	while (p.cmd[p.i])
	{
		if (p.cmd[p.i] == ' ')
			p.i++;
		if (!cmd[p.i])
			return (p.result);
		p.start = p.i;
		add_next_arg(&p);
		parse_command_push_param(&p);
	}
	return (p.result);
}
