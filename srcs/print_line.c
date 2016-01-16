/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:16:12 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/16 16:35:49 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char		*get_home_with_tilde(char *cwd)
{
	char	*after_home;
	char	*home;

	home = get_home_directory();
	if (ft_strstr(cwd, home) != cwd)
	{
		free(home);
		return (cwd);
	}
	if (!(after_home = ft_strsub(cwd, ft_strlen(home), ft_strlen(cwd) - ft_strlen(home))))
		error_quit("Failed to malloc PS1");
	free(cwd);
	if (!(cwd = ft_strjoin_free2("~", after_home)))
		error_quit("Failed to malloc PS1");
	free(home);
	return (cwd);
}

void				print_line(void)
{
	char	*host;
	char	*line;
	char	*user;
	char	*cwd;

	host = get_host_name();
	cwd = get_working_directory();
	user = get_username();
	cwd = get_home_with_tilde(cwd);
	if (!(line = ft_strjoin_free2("\e[1;37m[", user)))
		error_quit("Failed to malloc PS1");
	if (!(line = ft_strjoin_free1(line, "@")))
		error_quit("Failed to malloc PS1");
	if (!(line = ft_strjoin_free3(line, host)))
		error_quit("Failed to malloc PS1");
	if (!(line = ft_strjoin_free1(line, "] \e[0;32m")))
		error_quit("Failed to malloc PS1");
	if (!(line = ft_strjoin_free3(line, cwd)))
		error_quit("Failed to malloc PS1");
	if (!(line = ft_strjoin_free1(line, "\e[1;37m $ \e[0;37m")))
		error_quit("Failed to malloc PS1");
	ft_putstr(line);
	free(line);
}
