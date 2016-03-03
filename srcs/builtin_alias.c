/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_alias.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 18:03:01 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/03 14:37:43 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		action(t_env *env, char *val)
{
	(void)env;
	(void)val;
}

int				builtin_alias(t_env *env, char **datas, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		action(env, datas[i]);
		i++;
	}
	return (1);
}
