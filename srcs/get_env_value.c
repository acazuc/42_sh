/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:15:00 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/11 10:18:15 by acazuc           ###   ########.fr       */
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
	key = ft_strjoin(key, "=");
	i = 0;
	while (g_env.ev[i])
	{
		if (ft_strstr(g_env.ev[i], key) == g_env.ev[i])
		{
			ret = ft_strsub(g_env.ev[i]
			, ft_strlen(key)
			, ft_strlen(g_env.ev[i]) - ft_strlen(key));
			free(key);
			return (ret);
		}
		i++;
	}
	return (NULL);
}
