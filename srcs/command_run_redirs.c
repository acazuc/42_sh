/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_run_redirs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 10:40:06 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/23 14:35:58 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	command_run_redirs(t_env *env, char *cmd)
{
	t_parser	parser;
	char		*arg;
	int			was_pipe;
	int			start;
	int			i;

	parse_command_init(&parser, cmd);
	was_pipe = 0;
	i = 0;
	while (cmd[i])
	{
		while (cmd[i] && cmd[i] == ' ')
			i++;
		start = i;
		while (cmd[i] && (parser.in_dquote || parser.in_squote || cmd[i] != ' '))
		{
			if (cmd[i] == '|' && !(parser.in_squote) && !(parser.in_dquote)
					&& (i == 0 || cmd[i - 1] != '\\'))
			{
				if (i != 0 && cmd[i - 1] != ' ')
				{
					if (!(arg = ft_strsub(cmd, start, i - start)))
						error_quit("Failed to malloc new cmd arg");
					parse_command_add_param(&(parser.result), arg);
				}
				command_run_piped(env, parser.result, was_pipe ? PIPE_IN_OUT : PIPE_OUT);
				was_pipe = 1;
				i++;
				while (cmd[i] && cmd[i] == ' ')
					i++;
				start = i;
				parse_command_reset(&parser);
			}
			parse_command_quotes(&parser, i);
			i++;
		}
		if (!(arg = ft_strsub(cmd, start, i - start)))
			error_quit("Failed to malloc new cmd arg");
		parse_command_add_param(&(parser.result), arg);
		i++;
	}
	command_run_piped(env, parser.result, was_pipe ? PIPE_IN : PIPE_NONE);
}
