/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_check_pipes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 16:50:02 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/16 11:03:30 by acazuc           ###   ########.fr       */
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
			if (!args[i + 1] || !ft_strcmp(args[i + 1], "|"))
			{
				ft_putendl_fd("cash: parse error near `|'", 2);
				return (0);
			}
		}
		i++;
	}
	return (1);
}
