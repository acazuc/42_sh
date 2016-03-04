/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:41:27 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/04 14:08:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int		get_len(char **datas)
{
	int		len;

	len = 0;
	while (datas[len])
		len++;
	return (len);
}

int				builtins(t_env *env, char **datas)
{
	int		len;

	len = get_len(datas);
	if (len == 0)
		return (0);
	if (!ft_strcmp(datas[0], "exit"))
		exit(1);
	if (!ft_strcmp(datas[0], "about"))
		return (builtin_about(env, datas, len));
	else if (!ft_strcmp(datas[0], "cd"))
		return (builtin_cd(env, datas, len));
	else if (!ft_strcmp(datas[0], "alias"))
		return (builtin_alias(env, datas, len));
	else if (!ft_strcmp(datas[0], "echo"))
		return (builtin_echo(env, datas, len));
	else if (!ft_strcmp(datas[0], "setenv"))
		return (builtin_setenv(env, datas, len));
	else if (!ft_strcmp(datas[0], "getenv"))
		return (builtin_getenv(env, datas, len));
	else if (!ft_strcmp(datas[0], "unsetenv"))
		return (builtin_unsetenv(env, datas, len));
	else if (!ft_strcmp(datas[0], "env"))
		return (builtin_env(env, datas, len));
	return (0);
}
