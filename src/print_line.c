/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:16:12 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 15:10:22 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

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

	host = get_host_name_before_point();
	user = get_username(env);
	ft_putstr("\033[1;37m[");
	ft_putstr(user);
	ft_putchar('@');
	ft_putstr(host);
	ft_putstr("] \033[1;31m");
	ft_putstr(env->cwd);
	ft_putstr("\033[0;37m \033[1;37m»\033[0;37m ");
	free(user);
	free(host);
}
