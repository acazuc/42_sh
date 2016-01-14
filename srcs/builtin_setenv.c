/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultin_setenv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 12:20:30 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/14 10:57:59 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_env	g_env;

static char		*build_new_occur(char *name, char *value)
{
	char	*result;

	if (!(result = ft_strjoin(name, "=")))
		return (NULL);
	if (!(result = ft_strjoin_free1(result, value)))
		return (NULL);
	return (result);
}

static int		push_new_entry(char *name, char *value)
{
	char	**new_tab;
	char	*entry;
	int		len;

	if (!(entry = build_new_occur(name, value)))
		error_quit("Failed to malloc new entry");
	len = 0;
	while (g_env.ev[len])
		len++;
	if (!(new_tab = malloc(sizeof(*new_tab) * (len + 2))))
		error_quit("Failed to malloc new env tab");
	len = 0;
	while (g_env.ev[len])
	{
		new_tab[len] = g_env.ev[len];
		len++;
	}
	new_tab[len] = entry;
	new_tab[++len] = NULL;
	free(g_env.ev);
	g_env.ev = new_tab;
	return (1);
}

int				builtin_setenv(char **datas, int len)
{
	char	*occur;
	int		i;

	if (len != 3)
	{
		ft_putendl("setenv: Invalid arguments");
		return (-1);
	}
	occur = NULL;
	i = 0;
	while (g_env.ev[i])
	{
		if (ft_strstr(g_env.ev[i], datas[1]) == g_env.ev[i]
				&& g_env.ev[i][ft_strlen(datas[1])] == '=')
		{
			free(g_env.ev[i]);
			if (!(g_env.ev[i] = build_new_occur(datas[1], datas[2])))
				error_quit("Failed to malloc new entry");
			return (1);
		}
		i++;
	}
	return (push_new_entry(datas[1], datas[2]));
}
