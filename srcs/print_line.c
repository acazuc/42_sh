/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:16:12 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/10 16:34:09 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	print_line(void)
{
	char	*line;
	char	*user;
	char	*cwd;

	cwd = get_working_directory();
	user = get_username();
	line = ft_strjoin_free2("\e[1;37m[", user);
	line = ft_strjoin_free1(line, "] \e[0;32m");
	line = ft_strjoin_free3(line, cwd);
	line = ft_strjoin_free1(line, "\e[1;37m $ \e[0;37m");
	ft_putstr(line);
}
