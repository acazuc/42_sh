/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_about.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:01:27 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/24 16:03:53 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		builtin_about(t_env *env, char **datas, int len)
{
	(void)env;
	(void)datas;
	(void)len;
	ft_putendl("==========minishell==========");
	ft_putendl("                             ");
	ft_putendl("By acazuc                    ");
	return (1);
}
