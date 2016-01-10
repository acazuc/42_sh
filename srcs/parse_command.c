/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:51:33 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/10 16:06:53 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		parse_command(t_command *command, char *command_line)
{
	char	**datas;
	int		len;

	datas = ft_strsplit(command_line, ' ');
	len = 0;
	while (datas[len])
		len++;
	if (builtins(datas, len))
		return (0);
	if (!(command->params = malloc(sizeof(*command->params) * (len + 2))))
		return (0);
	command->params[len + 1] = NULL;
	len = 0;
	while (datas[len])
	{
		command->params[len] = datas[len];
		len++;
	}
	free(command_line);
	return (1);
}
