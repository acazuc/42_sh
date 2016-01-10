/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:45:32 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/10 16:01:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int		exit_error()
{
	ft_putendl("cash: exit: Illegal exit value (int expected)");
	return (-1);
}

int				builtin_exit(char **datas, int len)
{
	int		old_status;
	int		status;
	int		i;

	if (len == 1)
		exit(0);
	else if (len > 2)
		return (-1);
	status = 0;
	i = 0;
	while (datas[1][i])
	{
		if (i < '0' || i > '9')
			return (exit_error());
		old_status = status;
		status = status * 10 + datas[1][i] - '0';
		if (status / 10 != old_status)
			return (exit_error());
	}
	exit(status);
}
