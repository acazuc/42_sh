/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_about.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:01:27 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/03 14:37:36 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		builtin_about(t_env *env, char **datas, int len)
{
	(void)env;
	(void)datas;
	(void)len;
	ft_putendl("cash by acazuc");
	return (1);
}
