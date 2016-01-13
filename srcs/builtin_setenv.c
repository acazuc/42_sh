/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultin_setenv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 12:20:30 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/12 08:35:19 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_env	g_env;

int		builtin_setenv(char **datas, int len)
{
	char	*occur;
	int		i;

	if (len != 3)
	{
		ft_putstr("Invalid arguments");
		return (-1);
	}
	occur = NULL;
	i = 0;
	while (g_env.ev[i])
	{
		if (ft_strstr(g_env.ev[i], datas[1]) == g_env.ev[i] && g_env.ev[i][ft_strlen(datas[1])] == '=')
		{
			return (1);
		}
	}
	return (0);
}
