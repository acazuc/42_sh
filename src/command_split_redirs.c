/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_split_redirs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 15:56:55 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/16 10:21:25 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		init(t_redir_manager *m)
{
	int					i;
	
	i = 0;
	while (i < 10)
	{
		m->old_fd[i] = 0;
		m->closed[i] = 0;
		m->has_changed[i] = 0;
		i++;
	}
}

static int		operate_redir_out(t_redir_manager *m, char **cmd, size_t *i)
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
	j++;
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
	else
	{
		(*i)++;
		if (fd == '&' - '0')
		{
			if (!redir_out_add_file(m, 1, append, cmd[*i])
					|| !redir_out_add_file(m, 2, append, cmd[*i]))
				return (0);
		}
		else if (!redir_out_add_file(m, fd, append, cmd[*i]))
			return (0);
	}
	return (1);
}

static int		operate_redir_in(t_redir_manager *m, char **cmd, size_t *i)
{
	int		fd;
	int		j;

	fd = 0;
	j = 0;
	if (cmd[*i][j] != '<')
		fd = cmd[*i][j++] - '0';
	j++;
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

int			command_split_redirs(t_env *env, char **cmd)
{
	t_redir_manager		m;
	size_t				i;
	char				**sub;
	int					has_redired;

	init(&m);
	i = 0;
	has_redired = 0;
	if (!(sub = malloc(sizeof(*sub))))
		ERROR("Failed to malloc split sub");
	sub[0] = NULL;
	while (cmd[i])
	{
		if (cmd[i][0] == '>' || ((cmd[i][0] == '&' || ft_isdigit(cmd[i][0])) && cmd[i][1] == '>'))
		{
			has_redired = 1;
			if (!(operate_redir_out(&m, cmd, &i)))
			{
				redir_reset(&m);
				return (0);
			}
		}
		else if (cmd[i][0] == '<' || (ft_isdigit(cmd[i][0]) && cmd[i][1] == '<'))
		{
			has_redired = 1;
			if (!operate_redir_in(&m, cmd, &i))
			{
				redir_reset(&m);
				return (0);
			}
		}
		else if (has_redired)
			command_run(env, sub);
		else
			command_split_push(&sub, cmd[i]);
		i++;
	}
	if (sub[0])
		command_run(env, sub);
	redir_reset(&m);
	return (1);
}
