/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_value_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:15:00 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 16:39:36 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*env_value_get(t_env *env, char *key)
{
	char	*ret;
	int		i;

	if (!key)
		return (NULL);
	if (!(key = ft_strjoin(key, "=")))
		ERROR("Failed to malloc env key");
	i = 0;
	while (env->ev[i])
	{
		if (ft_strstr(env->ev[i], key) == env->ev[i])
		{
			if (!(ret = ft_strsub(env->ev[i], ft_strlen(key)
			, ft_strlen(env->ev[i]) - ft_strlen(key))))
				ERROR("Failed to malloc env value");
			free(key);
			return (ret);
		}
		i++;
	}
	free(key);
	return (NULL);
}
