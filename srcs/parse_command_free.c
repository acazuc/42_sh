/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 13:36:37 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/24 13:38:12 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	parse_command_free(t_parser *parser)
{
	int		i;

	i = 0;
	while (parser->result[i])
	{
		free(parser->result[i]);
		i++;
	}
	free(parser->result);
}
