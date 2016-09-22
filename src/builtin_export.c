/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:27:36 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 16:41:28 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int		action_undo(char *equals, char tmp, char *msg)
{
	equals[0] = tmp;
	ft_putendl_fd(msg, 2);
	return (-1);
}

static int		action(t_env *env, char *value)
{
	char	*equals;
	char	*key;
	char	*val;
	char	tmp;

	equals = ft_strchr(value, '=');
	if (!equals)
		return (-1);
	key = value;
	val = equals + 1;
	tmp = equals[0];
	equals[0] = '\0';
	if (!ft_strlen(val))
		return (action_undo(equals, tmp, "cash: export: invalid export key"));
	if (!equals[1])
		return (action_undo(equals, tmp, "cash: export: invalid export value"));
	env_value_set(env, key, val);
	equals[0] = tmp;
	return (1);
}

int				builtin_export(t_env *env, char **datas, int len)
{
	int		i;

	i = 1;
	while (i < len)
	{
		if (action(env, datas[i]) == -1)
			return (-1);
		i++;
	}
	return (1);
}
