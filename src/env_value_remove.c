/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_value_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:33:53 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 16:37:23 by acazuc           ###   ########.fr       */
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

void			env_value_remove(t_env *env, char *key)
{
	int		i;

	i = 0;
	while (env->ev[i])
	{
		if (ft_strstr(env->ev[i], key) == env->ev[i]
				&& env->ev[i][ft_strlen(key)] == '=')
			delete_entry(env, i);
		i++;
	}
}
