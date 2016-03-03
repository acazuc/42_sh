/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:54:46 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/03 11:27:21 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	error(char *dir)
{
	ft_putstr("cd: no such file or directory: ");
	ft_putendl(dir);
	return (1);
}

static int	changedir(t_env *env, char *dir)
{
	char	*pwd;

	if (!dir && !(dir = get_env_value(env, "HOME")))
		ERROR("Failed to get home dir");
	else if (!ft_strcmp(dir, "-"))
	{
		if (!(dir = get_env_value(env, "OLDPWD")))
			ERROR("Failed to get oldpwd");
	}
	if (!chdir(dir))
	{
		if (!(pwd = get_env_value(env, "PWD")))
			ERROR("Failed to get current pwd");
		set_env_value(env, "OLDPWD", pwd);
		free(pwd);
		if (!(pwd = get_working_directory()))
			ERROR("Failed to get current pwd");
		set_env_value(env, "PWD", pwd);
		free(pwd);
		return (1);
	}
	return (error(dir));
}

int			builtin_cd(t_env *env, char **datas, int len)
{
	(void)len;
	return (changedir(env, datas[1]));
}
