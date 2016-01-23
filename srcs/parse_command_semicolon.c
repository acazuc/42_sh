/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_semicolon.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 17:34:45 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/23 11:15:03 by acazuc           ###   ########.fr       */
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

static void		parser_init(t_parser *parser, int *start, int i)
{
	*start = i;
	parser->in_dquote = 0;
	parser->in_squote = 0;
}

char			**parse_command_semicolon(char *cmd)
{
	t_parser	parser;
	char		*arg;
	int			start;
	int			i;

	parse_command_init(&parser, cmd);
	i = 0;
	while (parser.cmd[i])
	{
		parser_init(&parser, &start, i);
		while (cmd[i] && (parser.in_dquote || parser.in_squote
					|| cmd[i] == ';' || i == 0 || cmd[i - 1] == '\\'))
			check_quotes_split(&parser, i++, &start);
		if (!(arg = ft_strsub(cmd, start, i - start)))
			error_quit("Failed to malloc new cmd args");
		parse_command_add_param(&(parser.result), arg);
		i++;
	}
	return (parser.result);
}
