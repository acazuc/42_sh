/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_delenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 10:47:20 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 14:00:05 by acazuc           ###   ########.fr       */
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
		ERROR("Failed to malloc new env tab");
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
		ft_putendl_fd("cash: unsetenv: Invalid arguments", 2);
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
	ft_putstr_fd("cash: unsetenv: Unknown env entry \"", 2);
	ft_putstr_fd(datas[1], 2);
	ft_putendl_fd("\"", 2);
	return (-1);
}
