/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:15:46 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/27 16:11:37 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		builtin_echo(t_env *env, char **datas, int len)
{
	size_t	i;
	int		not;

	not = 0;
	i = 1;
	if (len < 2)
		ft_putchar('\n');
	if (!ft_strcmp(datas[1], "-n"))
	{
		not = 1;
		++i;
	}
	while (datas[i])
	{
		ft_putstr(datas[i]);
		if (datas[i + 1])
			ft_putchar(' ');
		else if (!not)
			ft_putchar('\n');
		i++;
	}
	(void)env;
	return (1);
}
