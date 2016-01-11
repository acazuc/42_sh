/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:04:51 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/11 10:21:20 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_env	g_env;

char	*get_path()
{
	char	*path;

	path = get_env_value("PATH");
	if (!path)
		return (ft_strdup("PATH"));
	return (path);
}
