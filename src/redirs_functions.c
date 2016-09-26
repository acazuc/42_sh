/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 09:10:15 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/26 19:45:33 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		redir_add(t_redir_manager *m, int fd_in, int fd_out, int from_file)
{
	if (!m->has_changed[fd_in])
	{
		if ((m->old_fd[fd_in] = dup(fd_in)) == -1)
			return (0);
		m->has_changed[fd_in] = 1;
	}
	if (!from_file && !m->has_changed[fd_out])
	{
		if ((m->old_fd[fd_out] = dup(fd_out)) == -1)
			return (0);
		m->has_changed[fd_out] = 1;
	}
	if (dup2(fd_out, fd_in) == -1)
		return (0);
	if (close(fd_out) == -1)
		return (0);
	return (1);
}

int		redir_close(t_redir_manager *m, int fd)
{
	if (!m->closed[fd])
	{
		if (!m->has_changed[fd])
		{
			if ((m->old_fd[fd] = dup(fd)) == -1)
				return (0);
			m->has_changed[fd] = 1;
		}
		if (close(fd) == -1)
			return (0);
		m->closed[fd] = 1;
	}
	return (1);
}

int		redir_in_add_file(t_redir_manager *m, int fd, char *file)
{
	int		file_fd;
	int		flags;

	flags = O_RDONLY;
	if ((file_fd = open(file, flags)) == -1)
	{
		ft_putstr_fd("cash: can't open: ", 2);
		ft_putendl_fd(file, 2);
		return (0);
	}
	return (redir_add(m, fd, file_fd, 1));
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
	if ((file_fd = open(file, flags, 0644)) == -1)
	{
		ft_putstr_fd("cash: can't open: ", 2);
		ft_putendl_fd(file, 2);
		return (0);
	}
	return (redir_add(m, fd, file_fd, 1));
}

void	redir_reset(t_redir_manager *m)
{
	int		i;

	i = 0;
	while (i < 10)
	{
		if (m->has_changed[i])
		{
			if (dup2(m->old_fd[i], i) == -1)
				ERROR("Failed to dup2");
			if (close(m->old_fd[i]) == -1)
				ERROR("Failed to dup2");
		}
		i++;
	}
}
