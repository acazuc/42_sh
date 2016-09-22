/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_username.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:24:53 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 16:56:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*get_username(t_env *env)
{
	char	*env_name;

	env_name = env_value_get(env, "USER");
	if (!env_name)
	{
		if (!(env_name = ft_strnew(0)))
			ERROR("strdup failed");
		return (env_name);
	}
	return (env_name);
}
