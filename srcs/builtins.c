/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:41:27 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/14 11:08:57 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		builtins(char **datas, int len)
{
	while (datas[len])
		len++;
	if (len == 0)
		return (0);
	if (!ft_strcmp(datas[0], "exit"))
		return (builtin_exit(datas, len));
	else if (!ft_strcmp(datas[0], "cd"))
		return (builtin_cd(datas, len));
	else if (!ft_strcmp(datas[0], "setenv"))
		return (builtin_setenv(datas, len));
	else if (!ft_strcmp(datas[0], "getenv"))
		return (builtin_getenv(datas, len));
	else if (!ft_strcmp(datas[0], "delenv"))
		return (builtin_delenv(datas, len));
	else if (!ft_strcmp(datas[0], "allenv"))
		return (builtin_allenv(datas, len));
	return (0);
}
