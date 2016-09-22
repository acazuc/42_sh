/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:16:12 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 12:11:37 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char			*get_home_with_tilde(t_env *env, char *cwd)
{
	char	*after_home;
	char	*home;

	home = get_home_directory(env);
	if (ft_strstr(cwd, home) != cwd)
	{
		free(home);
		return (cwd);
	}
	if (!(after_home = ft_strsub(cwd, ft_strlen(home)
					, ft_strlen(cwd) - ft_strlen(home))))
		ERROR("Failed to malloc PS1");
	free(cwd);
	free(home);
	if (!(cwd = ft_strjoin_free2("~", after_home)))
		ERROR("Failed to malloc PS1");
	return (cwd);
}

static char			*get_host_name_before_point(void)
{
	char	*host;
	char	*ret;
	char	*chr;

	host = get_host_name();
	if ((chr = ft_strchr(host, '.')))
	{
		if (!(ret = ft_strsub(host, 0, chr - host)))
			ERROR("Failed to malloc PS1 hostname");
		free(host);
		return (ret);
	}
	return (host);
}

void				print_line(t_env *env)
{
	char	*host;
	char	*user;
	char	*cwd;

	host = get_host_name_before_point();
	cwd = get_working_directory();
	user = get_username(env);
	cwd = get_home_with_tilde(env, cwd);
	ft_putstr("\033[1;37m[");
	ft_putstr(user);
	ft_putchar('@');
	ft_putstr(host);
	ft_putstr("] \033[0;31m");
	ft_putstr(cwd);
	ft_putstr("\033[1;37m » \033[0;37m");
	free(user);
	free(host);
	free(cwd);
}
