/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_allenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 11:03:52 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/23 11:26:46 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		builtin_env(t_env *env, char **datas, int len)
{
	int		i;

	i = 0;
	while (env->ev[i])
	{
		ft_putendl(env->ev[i]);
		i++;
	}
	(void)datas;
	(void)len;
	return (1);
}
