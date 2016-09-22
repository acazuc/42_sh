/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_username.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:24:53 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/14 09:12:27 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*get_username(t_env *env)
{
	char	*env_name;

	env_name = get_env_value(env, "USER");
	if (!env_name)
		return (ft_strdup("USER"));
	return (env_name);
}
