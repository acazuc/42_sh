/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:54:46 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 16:40:41 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include <errno.h>

static int	error(char *dir)
{
	if (errno == ENOTDIR)
		ft_putstr_fd("cash: cd: not a directory: ", 2);
	else if (errno == EPERM || errno == EACCES)
		ft_putstr_fd("cash: cd: you don't have permission: ", 2);
	else
		ft_putstr_fd("cash: cd: no such file or directory: ", 2);
	ft_putendl_fd(dir, 2);
	return (-1);
}

static int	changedir(t_env *env, char *dir)
{
	char	*pwd;

	if (!dir && !(dir = env_value_get(env, "HOME")))
		ERROR("Failed to get home dir");
	else if (!ft_strcmp(dir, "-"))
	{
		if (!(dir = env_value_get(env, "OLDPWD")))
			ERROR("Failed to get oldpwd");
	}
	if (!chdir(dir))
	{
		if (!(pwd = env_value_get(env, "PWD")))
			ERROR("Failed to get current pwd");
		env_value_set(env, "OLDPWD", pwd);
		free(pwd);
		if (!(pwd = get_working_directory()))
			ERROR("Failed to get current pwd");
		env_value_set(env, "PWD", pwd);
		free(pwd);
		return (1);
	}
	return (error(dir));
}

int			builtin_cd(t_env *env, char **datas, int len)
{
	int		ret;

	(void)len;
	ret = changedir(env, datas[1]);
	if (ret == 1)
	{
		free(env->cwd);
		if (!(env->cwd = get_working_directory()))
			ERROR("Failed to get current working directory");
		if (!(env->cwd = get_home_with_tilde(env, env->cwd)))
			ERROR("Failde to get current working directory with tilde");
	}
	return (ret);
}
