/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_semicolon.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 17:34:45 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/23 13:11:52 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		check_quotes_split(t_parser *parser, int i, int *start)
{
	char		*arg;
	
	parse_command_quotes(parser, i);
	if (parser->cmd[i] == ';' && (i == 0 || parser->cmd[i - 1] != '\\')
		&& !(parser->in_squote) && !(parser->in_dquote))
	{
		if (!(arg = ft_strsub(parser->cmd, *start, i - *start)))
			error_quit("Failed to malloc new cmd arg");
		parse_command_add_param(&(parser->result), arg);
		*start = i + 1;
	}
}

char			**parse_command_semicolon(char *cmd)
{
	t_parser	parser;
	char		*arg;
	int			start;
	int			i;

	parse_command_init(&parser, cmd);
	start = 0;
	parser.in_dquote = 0;
	parser.in_squote = 0;
	i = 0;
	while (parser.cmd[i])
		check_quotes_split(&parser, i++, &start);
	if (!(arg = ft_strsub(parser.cmd, start, i - start)))
		error_quit("Failed to malloc new cmd arg");
	parse_command_add_param(&(parser.result), arg);
	return (parser.result);
}
