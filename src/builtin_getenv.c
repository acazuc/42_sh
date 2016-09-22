/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_getenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 08:33:21 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 13:59:41 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		builtin_getenv(t_env *env, char **datas, int len)
{
	char	*value;
	int		i;

	if (len == 1)
	{
		ft_putendl_fd("cash: getenv: Invalid arguments", 2);
		return (-1);
	}
	else
	{
		i = 1;
		while (i < len)
		{
			ft_putstr(datas[i]);
			ft_putchar('=');
			if (!(value = get_env_value(env, datas[i])))
				ft_putendl("");
			else
				ft_putendl(value);
			i++;
		}
		return (1);
	}
}
