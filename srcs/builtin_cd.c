/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:54:46 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/23 11:20:21 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	changedir(char *dir)
{
	if (!dir)
		return (0);
	if (!chdir(dir))
		return (1);
	return (-1);
}

int			builtin_cd(t_env *env, char **datas, int len)
{
	if (len == 1)
	{
		if (changedir(get_env_value(env, "HOME")))
			return (1);
		return (-1);
	}
	return (changedir(datas[1]));
}
