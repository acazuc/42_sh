/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:04:51 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/23 11:43:44 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*get_path(t_env *env)
{
	char	*path;

	path = get_env_value(env, "PATH");
	if (!path)
		return (ft_strdup("PATH"));
	return (path);
}
