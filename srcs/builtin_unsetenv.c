/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_delenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 10:47:20 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/23 11:26:21 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int		delete_entry(t_env *env, int i)
{
	char	**new_tab;
	int		len;
	int		j;

	len = 0;
	while (env->ev[len])
		len++;
	if (!(new_tab = malloc(sizeof(*new_tab) * len)))
		error_quit("Failed to malloc  new env tab");
	len = 0;
	j = 0;
	while (env->ev[len])
	{
		if (len != i)
		{
			new_tab[j] = env->ev[len];
			j++;
		}
		len++;
	}
	new_tab[j] = NULL;
	free(env->ev);
	env->ev = new_tab;
	return (1);
}

int				builtin_unsetenv(t_env *env, char **datas, int len)
{
	int		i;

	if (len != 2)
	{
		ft_putendl("unsetenv: Invalid arguments");
		return (-1);
	}
	i = 0;
	while (env->ev[i])
	{
		if (ft_strstr(env->ev[i], datas[1]) == env->ev[i]
					&& env->ev[i][ft_strlen(datas[1])] == '=')
			return (delete_entry(env, i));
		i++;
	}
	ft_putstr("unsetenv: Unknown env entry \"");
	ft_putstr(datas[1]);
	ft_putendl("\"");
	return (0);
}
