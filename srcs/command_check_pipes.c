/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_check_pipes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 16:50:02 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/06 16:54:23 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		command_check_pipes(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		if (!ft_strcmp(args[i], "|"))
		{
			if (!args[i] || !ft_strcmp(args[i], "|"))
			{
				ft_putendl("cash: parse error near `|'");
				return (0);
			}
		}
		i++;
	}
	return (1);
}
