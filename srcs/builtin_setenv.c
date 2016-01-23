/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultin_setenv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 12:20:30 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/23 11:24:46 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char		*build_new_occur(char *name, char *value)
{
	char	*result;

	if (!(result = ft_strjoin(name, "=")))
		return (NULL);
	if (!(result = ft_strjoin_free1(result, value)))
		return (NULL);
	return (result);
}

static int		push_new_entry(t_env *env, char *name, char *value)
{
	char	**new_tab;
	char	*entry;
	int		len;

	if (!(entry = build_new_occur(name, value)))
		error_quit("Failed to malloc new entry");
	len = 0;
	while (env->ev[len])
		len++;
	if (!(new_tab = malloc(sizeof(*new_tab) * (len + 2))))
		error_quit("Failed to malloc new env tab");
	len = 0;
	while (env->ev[len])
	{
		new_tab[len] = env->ev[len];
		len++;
	}
	new_tab[len] = entry;
	new_tab[++len] = NULL;
	free(env->ev);
	env->ev = new_tab;
	return (1);
}

int				builtin_setenv(t_env *env, char **datas, int len)
{
	int		i;

	if (len != 3)
	{
		ft_putendl("setenv: Invalid arguments");
		return (-1);
	}
	i = 0;
	while (env->ev[i])
	{
		if (ft_strstr(env->ev[i], datas[1]) == env->ev[i]
				&& env->ev[i][ft_strlen(datas[1])] == '=')
		{
			free(env->ev[i]);
			if (!(env->ev[i] = build_new_occur(datas[1], datas[2])))
				error_quit("Failed to malloc new entry");
			return (1);
		}
		i++;
	}
	return (push_new_entry(env, datas[1], datas[2]));
}
