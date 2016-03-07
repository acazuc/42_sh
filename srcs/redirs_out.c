/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 09:10:15 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/07 10:05:31 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
 * [fd_in] > & [fd_out]
 */

void	redirs_out_add(t_redir_manager *m, int fd_in, int fd_out)
{
	if (!m->has_changed[fd_in])
	{
		dup2(fd_in, m->old_fd[fd_in]);
		m->has_changed[fd_in] = 1'
	}
	if (!m->has_changed[fd_out] && fd_out > 0 && fd_out < 10)
	{
		dup(fd_out, m_old_fd[fd_out]);
		m->haschanged[fd_out] = 1;
	}
	dup2(fd_out, fd_in);
	m->do_redir[fd_in] = 1;
	m->to_redir[fd_in] = fd_out;
}

void	redirs_out_close(t_redir_manager *m, int fd)
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

int		redirs_out_add_file(t_redir_manager *m, int fd, int append, char *file)
{
	int		file_fd;
	int		flags;

	flags = O_WRONLY | O_CREAT;
	if (append)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	if ((file_fd = open(file, flags, 0666)) == -1)
		return (0);
	redirs_out_add(m, fd, file_fd, append);
}
