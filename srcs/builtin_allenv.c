/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_allenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 11:03:52 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/14 11:11:43 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_env	g_env;

int		builtin_allenv(char **datas, int len)
{
	int		i;

	i = 0;
	while (g_env.ev[i])
	{
		ft_putendl(g_env.ev[i]);
		i++;
	}
	(void)datas;
	(void)len;
	return (1);
}
