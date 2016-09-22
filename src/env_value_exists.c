/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_value_exists.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:37:30 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 16:38:48 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		env_value_exists(t_env *env, char *key)
{
	int		i;

	i = 0;
	while (env->ev[i])
	{
		if (ft_strstr(env->ev[i], key) == env->ev[i]
				&& env->ev[i][ft_strlen(key)] == '=')
			return (1);
	}
	return (0);
}
