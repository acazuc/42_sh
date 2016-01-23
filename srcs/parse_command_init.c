/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 13:23:52 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/23 11:01:24 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	parse_command_init(t_parser *parser, char *cmd)
{
	if (!(parser->result = malloc(sizeof(*parser->result))))
		error_quit("Failed to malloc parser result str");
	parser->result[0] = NULL;
	parser->cmd = cmd;
}
