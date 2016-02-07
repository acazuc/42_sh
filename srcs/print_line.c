/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:16:12 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/07 09:42:42 by acazuc           ###   ########.fr       */
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
		error_quit("Failed to malloc PS1");
	free(cwd);
	if (!(cwd = ft_strjoin_free2("~", after_home)))
		error_quit("Failed to malloc PS1");
	free(home);
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
			error_quit("Failed to malloc PS1");
		free(host);
		return (ret);
	}
	return (host);
}

void				print_line(t_env *env)
{
	char	*host;
	char	*line;
	char	*user;
	char	*cwd;

	host = get_host_name_before_point();
	cwd = get_working_directory();
	user = get_username(env);
	cwd = get_home_with_tilde(env, cwd);
	if (!(line = ft_strjoin_free2("\033[1;37m[", user)))
		error_quit("Failed to malloc PS1");
	if (!(line = ft_strjoin_free1(line, "@")))
		error_quit("Failed to malloc PS1");
	if (!(line = ft_strjoin_free3(line, host)))
		error_quit("Failed to malloc PS1");
	if (!(line = ft_strjoin_free1(line, "] \033[0;33m")))
		error_quit("Failed to malloc PS1");
	if (!(line = ft_strjoin_free3(line, cwd)))
		error_quit("Failed to malloc PS1");
	if (!(line = ft_strjoin_free1(line, "\033[1;37m $ \033[0;37m")))
		error_quit("Failed to malloc PS1");
	ft_putstr(line);
	free(line);
}
