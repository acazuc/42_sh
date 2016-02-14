/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:54:46 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/14 10:57:19 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	error(char *dir)
{
	ft_putstr("cd: no such file or directory: ");
	ft_putstr(dir);
	return (1);
}

static int	changedir(t_env *env, char *dir)
{
	char	*pwd;

	if (!dir)
		return (error(dir));
	if (!ft_strcmp(dir, "-"))
	{
		if (!(dir = get_env_value(env, "OLDPWD")))
			error_quit("Failed to get oldpwd");
	}
	if (!chdir(dir))
	{
		if (!(pwd = get_env_value(env, "PWD")))
			error_quit("Failed to get current pwd");
		set_env_value(env, "OLDPWD", pwd);
		free(pwd);
		if (!(pwd = get_working_directory()))
			error_quit("Failed to get current pwd");
		set_env_value(env, "PWD", pwd);
		free(pwd);
		return (1);
	}
	return (error(dir));
}

int			builtin_cd(t_env *env, char **datas, int len)
{
	if (len == 1)
		return (changedir(env, get_env_value(env, "HOME")));
	return (changedir(env, datas[1]));
}
