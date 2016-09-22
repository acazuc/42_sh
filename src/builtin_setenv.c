/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultin_setenv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 12:20:30 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/16 10:24:45 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int				builtin_setenv(t_env *env, char **datas, int len)
{
	if (len != 3)
	{
		ft_putendl_fd("cash: setenv: Invalid arguments", 2);
		return (1);
	}
	set_env_value(env, datas[1], datas[2]);
	return (1);
}
