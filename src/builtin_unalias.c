/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unalias.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 13:22:17 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 16:06:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			builtin_unalias(t_env *env, char **datas, int len)
{
	int		i;

	if (len < 2)
	{
		ft_putendl_fd("cash: unalias: not enough arguments", 2);
		return (-1);
	}
	i = 1;
	while (i < len)
	{
		if (!alias_remove(env, datas[i]))
		{
			ft_putstr_fd("cash: unalias: no such linked list element: ", 2);
			ft_putendl_fd(datas[i], 2);
		}
		i++;
	}
	return (1);
}
