/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:15:46 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/26 19:22:37 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		builtin_echo(t_env *env, char **datas, int len)
{
	size_t	i;

	i = 1;
	if (!datas[1])
		ft_putchar('\n');
	while (datas[i])
	{
		ft_putstr(datas[i]);
		if (datas[i + 1])
			ft_putchar(' ');
		else
			ft_putchar('\n');
		i++;
	}
	(void)env;
	(void)len;
	return (1);
}
