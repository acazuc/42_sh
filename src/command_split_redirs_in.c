/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_split_redirs_in.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 14:24:18 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 14:37:03 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		command_split_redirs_in_init(int *fd, int *j, char **cmd
		, size_t *i)
{
	*fd = 0;
	*j = 0;
	if (cmd[*i][*j] != '<')
		*fd = cmd[*i][(*j)++] - '0';
	(*j)++;
}

int				command_split_redirs_in(t_redir_manager *m, char **cmd
		, size_t *i)
{
	int		fd;
	int		j;

	command_split_redirs_in_init(&fd, &j, cmd, i);
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
	else if (!((*i)++) || !redir_in_add_file(m, fd, cmd[*i]))
		return (0);
	return (1);
}
