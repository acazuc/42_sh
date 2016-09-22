/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_home_directory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 17:24:26 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/23 11:43:18 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*get_home_directory(t_env *env)
{
	char	*home;

	home = get_env_value(env, "HOME");
	if (!home)
		return (ft_strdup("HOME"));
	return (home);
}
