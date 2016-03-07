/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 09:10:15 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/07 15:12:17 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	redir_add(t_redir_manager *m, int fd_in, int fd_out, int from_file)
{
	if (!m->has_changed[fd_in])
	{
		dup2(fd_in, m->old_fd[fd_in]);
		m->has_changed[fd_in] = 1;
	}
	if (!from_file && !m->has_changed[fd_out])
	{
		dup2(fd_out, m->old_fd[fd_out]);
		m->has_changed[fd_out] = 1;
	}
	dup2(fd_out, fd_in);
	close(fd_out);
}

void	redir_close(t_redir_manager *m, int fd)
{
	if (!m->closed[fd])
	{
		if (!m->has_changed[fd])
		{
			dup2(fd, m->old_fd[fd]);
			m->has_changed[fd] = 1;
		}
		close(fd);
		m->closed[fd] = 1;
	}
}

int		redir_in_add_file(t_redir_manager *m, int fd, char *file)
{
	int		file_fd;
	int		flags;

	flags = O_RDONLY;
	if ((file_fd = open(file, flags, 0666)) == -1)
	{
		ft_putstr("cash: no such file or directory: ");
		ft_putendl(file);
		return (0);
	}
	redir_add(m, fd, file_fd, 1);
	return (1);
}

int		redir_out_add_file(t_redir_manager *m, int fd, int append, char *file)
{
	int		file_fd;
	int		flags;

	flags = O_WRONLY | O_CREAT;
	if (append)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	if ((file_fd = open(file, flags, 0666)) == -1)
	{
		ft_putstr("cash: no such file or directory: ");
		ft_putendl(file);
		return (0);
	}
	redir_add(m, fd, file_fd, 1);
	return (1);
}

void	redir_reset(t_redir_manager *m)
{
	int		i;

	i = 0;
	while (i < 10)
	{
		if (m->has_changed[i])
		{
			dup2(m->old_fd[i], i);
			close(m->old_fd[i]);
		}
		i++;
	}
}
