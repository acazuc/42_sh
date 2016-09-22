/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_alias.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 18:03:01 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 12:19:54 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int		action(t_env *env, char *val)
{
	char	*equals;

	equals = ft_strchr(val, '=');
	if (!equals)
		return (1);
	(void)env;
	ft_putstr("alias: ");
	ft_putendl(val);
	return (1);
}

int				builtin_alias(t_env *env, char **datas, int len)
{
	int		i;

	i = 1;
	while (i < len)
	{
		if (!action(env, datas[i]))
			return (0);
		i++;
	}
	return (1);
}
