/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:04:51 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/18 10:45:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*get_path(void)
{
	char	*path;

	path = get_env_value("PATH");
	if (!path)
		return (ft_strdup("PATH"));
	return (path);
}
