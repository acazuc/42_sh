/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_home_directory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 17:24:26 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/11 10:23:07 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*get_home_directory()
{
	char	*home;

	home = get_env_value("HOME");
	if (!home)
		return (ft_strdup("HOME"));
	return (ft_strdup(home));
}
