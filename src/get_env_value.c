/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:15:00 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/06 11:05:46 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*get_env_value(t_env *env, char *key)
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
