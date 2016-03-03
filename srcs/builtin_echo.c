/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:15:46 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/03 14:37:55 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		builtin_echo(t_env *env, char **datas, int len)
{
	size_t	i;

	i = 1;
	while (datas[i])
	{
		ft_putendl(datas[i]);
		i++;
	}
	(void)env;
	(void)len;
	return (1);
}
