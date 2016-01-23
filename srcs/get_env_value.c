/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:15:00 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/23 11:19:40 by acazuc           ###   ########.fr       */
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
		error_quit("Failed to malloc env key");
	i = 0;
	while (env->ev[i])
	{
		if (ft_strstr(env->ev[i], key) == env->ev[i])
		{
			if (!(ret = ft_strsub(env->ev[i], ft_strlen(key)
			, ft_strlen(env->ev[i]) - ft_strlen(key))))
				error_quit("Failed to malloc env value");
			free(key);
			return (ret);
		}
		i++;
	}
	return (NULL);
}
