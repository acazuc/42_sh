/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultin_setenv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 12:20:30 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/11 17:38:35 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_env	g_env;

int		builtin_setenv(char **datas, int len)
{
	char	**next_ev;
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
			free(g_env.ev[i]);
			g_env.ev[i] = ft_strjoin_fre1(ft_strjoin(datas[1], "="), datas[2]);
			return (1);
		}
	}
	i = 0;
	while (g_env.ev[i])
		i++;
	if (!(next_ev = malloc(sizeof(*next_ev) * (i + 2))))
		error_quit("Failed to malloc env");
	i = 0;
	while (g_env.ev[i])
	{
		next_ev[i] = g_env.ev[i];
		i++;
	}
	next_ev[i] = ft_strjoin_free1(ft_strjoin(datas[1], "="), datas[2]);
	return (1);
}
