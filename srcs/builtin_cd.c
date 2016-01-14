/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:54:46 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/14 08:38:01 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	changedir(char *dir)
{
	if (!dir)
		return (0);
	if (!chdir(dir))
		return (1);
	perror(dir);
	return (0);
}

int		builtin_cd(char **datas, int len)
{
	if (len == 1)
	{
		if (changedir(get_env_value("HOME")))
			return (1);
		return (-1);
	}
	if (changedir(datas[1]))
		return (1);
	return (-1);
}
