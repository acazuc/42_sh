/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_home_directory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 17:24:26 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 16:56:36 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*get_home_directory(t_env *env)
{
	char	*home;

	home = env_value_get(env, "HOME");
	if (!home)
	{
		if (!(home = ft_strnew(0)))
			ERROR("strdup failed");
		return (home);
	}
	return (home);
}
