/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_run_redirs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 10:40:06 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/15 10:13:53 by acazuc           ###   ########.fr       */
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

static void		init(t_parser *parser, char *cmd, int *was_pipe)
{
	parse_command_init(parser, cmd);
	*was_pipe = 0;
}

void			command_run_redirs(t_env *env, char *cmd)
{
	t_parser	p;
	int			was_pipe;

	init(&p, cmd, &was_pipe);
	while (cmd[p.i])
	{
		pass_spaces(cmd, &(p.i));
		p.start = p.i;
		while (cmd[p.i] && (p.in_dquote || p.in_squote || cmd[p.i] != ' '))
		{
			if (cmd[p.i] == '|' && !(p.in_squote) && !(p.in_dquote)
					&& (p.i == 0 || cmd[p.i - 1] != '\\'))
			{
				if (p.i != 0 && cmd[p.i - 1] != ' ')
					parse_command_push_param(&p);
				command_run_piped(env, p.result, was_pipe ? PIPE_IO : PIPE_O);
				reset_pipe(cmd, &was_pipe, &(p.i), &(p.start));
				parse_command_reset(&p);
			}
			parse_command_quotes(&p, p.i++);
		}
		if (p.i > p.start)
			parse_command_push_param(&p);
	}
	command_run_piped(env, p.result, was_pipe ? PIPE_I : PIPE_NO);
	free(cmd);
}
