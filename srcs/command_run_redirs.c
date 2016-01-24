/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_run_redirs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 10:40:06 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/24 13:40:41 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		pass_spaces(char *cmd, int *i)
{
	while (cmd[*i] && cmd[*i] == ' ')
		(*i)++;
}

static void		reset_pipe(char *cmd, int *was_pipe, int *i, int *start)
{
	*was_pipe = 1;
	(*i)++;
	pass_spaces(cmd, i);
	*start = *i;
}

static void		init(t_parser *parser, char *cmd, int *was_pipe, int *i)
{
	parse_command_init(parser, cmd);
	*was_pipe = 0;
	*i = 0;
}

void			command_run_redirs(t_env *env, char *cmd)
{
	t_parser	parser;
	int			was_pipe;
	int			start;
	int			i;

	init(&parser, cmd, &was_pipe, &i);
	while (cmd[i])
	{
		pass_spaces(cmd, &i);
		start = i;
		while (cmd[i] && (parser.in_dquote || parser.in_squote || cmd[i] != ' '))
		{
			if (cmd[i] == '|' && !(parser.in_squote) && !(parser.in_dquote)
					&& (i == 0 || cmd[i - 1] != '\\'))
			{
				if (i != 0 && cmd[i - 1] != ' ')
					parse_command_push_param(&(parser.result), cmd, start, i);
				command_run_piped(env, parser.result, was_pipe ? PIPE_IN_OUT : PIPE_OUT);
				reset_pipe(cmd, &was_pipe, &i, &start);
				parse_command_reset(&parser);
			}
			parse_command_quotes(&parser, i);
			i++;
		}
		if (i > start)
			parse_command_push_param(&(parser.result), cmd, start, i);
	}
	command_run_piped(env, parser.result, was_pipe ? PIPE_IN : PIPE_NONE);
}
