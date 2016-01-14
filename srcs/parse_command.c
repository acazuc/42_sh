/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:51:33 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/14 14:58:34 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		parse_command(t_command *command, char *command_line)
{
	char	**datas;
	int		len;

	datas = parse_command_params(command_line);
	free(command_line);
	len = 0;
	while (datas[len])
		len++;
	if (builtins(datas, len))
		return (0);
	if (len == 0)
		return (0);
	if (!(command->params = malloc(sizeof(*command->params) * (len + 1))))
		return (0);
	len = 0;
	while (datas[len])
	{
		command->params[len] = datas[len];
		len++;
	}
	len = 0;
	free(datas);
	command->params[len] = NULL;
	return (1);
}
