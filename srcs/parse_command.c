/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:51:33 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/13 20:21:39 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		parse_command(t_command *command, char *command_line)
{
	char	**datas;
	int		len;

	datas = ft_strsplit(command_line, ' ');
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
		if (datas[len][0] == '~')
		{
			command->params[len] = ft_strjoin_free3(get_home_directory(), ft_strsub(datas[len], 1, ft_strlen(datas[len]) - 1));
		}
		command->params[len] = datas[len];
		len++;
	}
	command->params[len] = NULL;
	return (1);
}
