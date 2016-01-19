/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:51:33 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/18 17:17:37 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		parse_line(char *command_line)
{
	char	**datas;
	int		len;

	datas = parse_command_splitter(command_line, ";");
	free(command_line);
	ft_putendl("NEW COMMAND");
	len = 0;
	while (datas[len])
		ft_putendl(datas[len++]);
	ft_putendl("END COMMAND");
	/*len = 0;
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
	command->params[len] = NULL;
	free(datas);*/
	return (1);
}