/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_reset.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 10:35:10 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/24 11:06:07 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	parse_command_reset(t_parser *parser)
{
	int		i;

	i = 0;
	while (parser->result[i])
	{
		free(parser->result[i]);
		i++;
	}
	free(parser->result);
	if (!(parser->result = malloc(sizeof(*parser->result))))
		error_quit("Failed to malloc parser result tab");
	parser->result[0] = NULL;
}
