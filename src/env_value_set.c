/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_value_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 09:22:37 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 16:57:41 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char		*build_new_occur(char *name, char *value)
{
	char	*result;

	if (!(result = ft_strjoin(name, "=")))
		ERROR("Failed to malloc new env value");
	if (!(result = ft_strjoin_free1(result, value)))
		ERROR("Failed to malloc new env value");
	return (result);
}

static void		push_new_entry(t_env *env, char *name, char *value)
{
	char	**new_tab;
	char	*entry;
	int		len;

	if (!(entry = build_new_occur(name, value)))
		ERROR("Failed to malloc new entry");
	len = 0;
	while (env->ev[len])
		len++;
	if (!(new_tab = malloc(sizeof(*new_tab) * (len + 2))))
		ERROR("Failed to malloc new env tab");
	len = 0;
	while (env->ev[len])
	{
		new_tab[len] = env->ev[len];
		len++;
	}
	new_tab[len++] = entry;
	new_tab[len++] = NULL;
	free(env->ev);
	env->ev = new_tab;
}

void			env_value_set(t_env *env, char *key, char *value)
{
	int		i;

	i = 0;
	while (env->ev[i])
	{
		if (ft_strstr(env->ev[i], key) == env->ev[i]
				&& env->ev[i][ft_strlen(key)] == '=')
		{
			free(env->ev[i]);
			if (!(env->ev[i] = build_new_occur(key, value)))
				ERROR("Failed to malloc new entry");
			return ;
		}
		i++;
	}
	push_new_entry(env, key, value);
}
