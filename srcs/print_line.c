/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:16:12 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/11 08:24:03 by acazuc           ###   ########.fr       */
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
	after_home = ft_strsub(cwd, ft_strlen(home), ft_strlen(cwd) - ft_strlen(home));
	free(cwd);
	cwd = ft_strjoin("~", after_home);
	free(after_home);
	return (cwd);
}

void				print_line(void)
{
	char	*line;
	char	*user;
	char	*cwd;

	cwd = get_working_directory();
	user = get_username();
	cwd = get_home_with_tilde(cwd);
	line = ft_strjoin_free2("\e[1;37m[", user);
	line = ft_strjoin_free1(line, "] \e[0;32m");
	line = ft_strjoin_free3(line, cwd);
	line = ft_strjoin_free1(line, "\e[1;37m $ \e[0;37m");
	ft_putstr(line);
	free(line);
}
