/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_source.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:24:01 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 15:49:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	return_error(char *str, char *file)
{
	ft_putstr_fd("cash: source: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(file, 2);
	return (-1);
}

int			builtin_source(t_env *env, char **datas, int len)
{
	char	*line;
	ssize_t	readed;
	int		fd;

	if (len < 2)
	{
		ft_putendl_fd("cash: source: not enough arguments", 2);
		return (-1);
	}
	if ((fd = open(datas[1], O_RDONLY)) == -1)
	{
		if (errno == ENOENT)
			return (return_error("no such file or directory", datas[1]));
		else if (errno == EACCES)
			return (return_error("you don't have permissions", datas[1]));
	}
	while ((line = read_next_line(fd, &readed)) && readed > 0)
	{
		command_execute(env, line);
	}
	close(fd);
	return (1);
}
