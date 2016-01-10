/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:51:33 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/10 15:41:10 by acazuc           ###   ########.fr       */
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
	if (len > 0)
	{
		if (!ft_strcmp(datas[0], "cd"))
		{
			if (len != 2)
				return (0);
			if (changedir(datas[1]))
				return (1);
			return (0);
		}
		else if (!ft_strcmp(datas[0], "exit"))
		{
			if (len == 1)
				exit(1);
			ft_putendl("cash: Invalid number of parameters");
			return (0);
		}
	}
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
