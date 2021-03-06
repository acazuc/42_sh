/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:54:46 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/06 21:55:25 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	error(char *dir)
{
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
	if (datas[1] && !ft_strcmp(datas[1], "."))
		return (1);
	ret = changedir(env, datas[1]);
	if (ret == 1)
	{
		free(env->cwd);
		if (!(env->cwd = get_working_directory()))
			ERROR("Failed to get current working directory");
		if (!(env->cwd = get_home_with_tilde(env, env->cwd)))
			ERROR("Failed to get current working directory with tilde");
	}
	return (ret);
}
