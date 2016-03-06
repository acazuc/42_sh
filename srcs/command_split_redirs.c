/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_split_redirs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 15:56:55 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/06 16:57:16 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		init(t_redir_manager *m)
{
	int					i;
	
	i = 0;
	while (i < 10)
	{
		m->closed[i] = 0;
		m->do_redir[i] = 0;
		m->to_redir[i] = i;
		m->is_append[i] = 0;
		i++;
	}
}

static void		operate_redir_out(t_redir_manager *m, char **cmd, size_t i)
{
	int		fd;
	int		j;

	fd = 1;
	j = 0;
	if (cmd[i][j] != '>')
		fd = cmd[i][j++] - '0';
	if (cmd[i][j] == '>' && cmd[i][j + 1] == '>')
	{
		m->is_append[fd] = 1;
		j++;
	}
	j++;
	if (cmd[i][j] == '&' && cmd[i][j + 1] == '-')
		m->closed[fd] = 1;
	else if (cmd[i][j] == '&' && ft_isdigit(cmd[i][j + 1]))
	{
		m->do_redir[fd] = 1;
		m->to_redir[fd] = cmd[i][j + 1] - '0';
	}
}

void	command_split_redirs(t_env *env, char **cmd, int pipe_type)
{
	t_redir_manager		m;
	size_t				i;
	char				**sub;

	init(&m);
	i = 0;
	if (!(sub = malloc(sizeof(*sub))))
		ERROR("Failed to malloc split sub");
	sub[0] = NULL;
	while (cmd[i])
	{
		if (cmd[i][0] == '>' || (ft_isdigit(cmd[i][0]) && cmd[i][1] == '>'))
			operate_redir_out(&m, cmd, i);
		i++;
	}
	(void)pipe_type;
	(void)env;
}
