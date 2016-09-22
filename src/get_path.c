/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:04:51 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 16:56:47 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*get_path(t_env *env)
{
	char	*path;

	path = env_value_get(env, "PATH");
	if (!path)
	{
		if (!(path = ft_strnew(0)))
			ERROR("strdup failed");
		return (path);
	}
	return (path);
}
