/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 17:36:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/26 17:38:54 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		builtin_exit(t_env *env, char **datas, int len)
{
	if (len == 1)
		exit(EXIT_SUCCESS);
	exit(ft_atoi(datas[1]));
	(void)env;
}
