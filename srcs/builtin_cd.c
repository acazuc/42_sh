/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:54:46 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/10 16:06:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		builtin_cd(char **datas, int len)
{
	if (len == 1)
	{
		if (changedir(getenv("HOME")))
			return (1);
		return (-1);
	}
	if (changedir(datas[1]))
		return (1);
	return (-1);
}
