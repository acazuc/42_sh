/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:41:27 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/10 16:06:52 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		builtins(char **datas, int len)
{
	if (len == 0)
		return (0);
	if (!ft_strcmp(datas[0], "exit"))
		return (builtin_exit(datas, len));
	else if (!ft_strcmp(datas[0], "cd"))
		return (builtin_cd(datas, len));
	return (0);
}
