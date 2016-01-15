/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_delenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 10:47:20 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/15 12:57:07 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_env	g_env;

static int		delete_entry(int i)
{
	char	**new_tab;
	int		len;
	int		j;

	len = 0;
	while (g_env.ev[len])
		len++;
	if (!(new_tab = malloc(sizeof(*new_tab) * len)))
		error_quit("Failed to malloc  new env tab");
	len = 0;
	j = 0;
	while (g_env.ev[len])
	{
		if (len != i)
		{
			new_tab[j] = g_env.ev[len];
			j++;
		}
		len++;
	}
	new_tab[j] = NULL;
	free(g_env.ev);
	g_env.ev = new_tab;
	return (1);
}

int		builtin_unsetenv(char **datas, int len)
{
	int		i;

	if (len != 2)
	{
		ft_putendl("unsetenv: Invalid arguments");
		return (-1);
	}
	i = 0;
	while (g_env.ev[i])
	{
		if (ft_strstr(g_env.ev[i], datas[1]) == g_env.ev[i]
					&& g_env.ev[i][ft_strlen(datas[1])] == '=')
		{
			return (delete_entry(i));
		}
		i++;
	}
	ft_putstr("unsetenv: Unknown env entry \"");
	ft_putstr(datas[1]);
	ft_putendl("\"");
	return (0);
}
