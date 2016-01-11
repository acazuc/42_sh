/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_username.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:24:53 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/11 10:21:27 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*get_username()
{
	char	*env_name;

	env_name = get_env_value("USER");
	if (!env_name)
		return (ft_strdup("USER"));
	return (ft_strdup(env_name));
}
