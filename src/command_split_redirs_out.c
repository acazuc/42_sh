/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_split_redirs_out.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 14:28:37 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/26 19:51:30 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int		command_split_else(t_redir_manager *m, char *file, int append
		, int fd)
{
	if (fd == '&' - '0')
	{
		if (!redir_out_add_file(m, 1, append, file)
				|| !redir_out_add_file(m, 2, append, file))
			return (0);
	}
	else if (!redir_out_add_file(m, fd, append, file))
		return (0);
	return (1);
}

int				command_split_redirs_out(t_redir_manager *m, char **cmd
		, size_t *i)
{
	int		append;
	int		fd;
	int		j;

	append = 0;
	fd = 1;
	j = 0;
	if (cmd[*i][j] != '>')
		fd = cmd[*i][j++] - '0';
	if (cmd[*i][j] == '>' && cmd[*i][j + 1] == '>')
		append = 1;
	j += append ? 2 : 1;
	if (cmd[*i][j] == '&' && cmd[*i][j + 1] == '-')
	{
		if (!redir_close(m, fd))
			return (0);
	}
	else if (cmd[*i][j] == '&' && ft_isdigit(cmd[*i][j + 1]))
	{
		if (!redir_add(m, fd, cmd[*i][j + 1] - '0', 0))
			return (0);
	}
	else if (!command_split_else(m, cmd[++(*i)], append, fd))
		return (0);
	return (1);
}
