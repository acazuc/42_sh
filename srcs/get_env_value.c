/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:15:00 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/14 10:27:56 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_env	g_env;

char	*get_env_value(char *key)
{
	char	*ret;
	int		i;

	if (!key)
		return (NULL);
	if (!(key = ft_strjoin(key, "=")))
		error_quit("Failed to malloc env key");
	i = 0;
	while (g_env.ev[i])
	{
		if (ft_strstr(g_env.ev[i], key) == g_env.ev[i])
		{
			if (!(ret = ft_strsub(g_env.ev[i]
			, ft_strlen(key)
			, ft_strlen(g_env.ev[i]) - ft_strlen(key))))
				error_quit("Failed to malloc env value");
			free(key);
			return (ret);
		}
		i++;
	}
	return (NULL);
}
