/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 10:17:28 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/23 11:10:01 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		parse_command_quotes(t_parser *parser, int i)
{
	if (parser->cmd[i] == '\'' && (i == 0 || parser->cmd[i - 1] != '\\')
			&& !(parser->in_dquote))
		parser->in_squote = !(parser->in_squote);
	if (parser->cmd[i] == '\"' && (i == 0 || parser->cmd[i - 1] != '\\')
			&& !(parser->in_squote))
		parser->in_dquote = !(parser->in_dquote);
}
