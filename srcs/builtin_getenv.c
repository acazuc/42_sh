/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_getenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 08:33:21 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/14 10:49:17 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		builtin_getenv(char **datas, int len)
{
	char	*value;
	int		i;

	if (len == 1)
	{
		ft_putendl("getenv: Invalid arguments");
		return (1);
	}
	else
	{
		i = 1;
		while (i < len)
		{
			ft_putstr(datas[i]);
			ft_putchar('=');
			if (!(value = get_env_value(datas[i])))
				ft_putendl("");
			else
				ft_putendl(value);
			i++;
		}
		return (1);
	}
}