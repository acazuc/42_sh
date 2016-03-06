/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_split_redirs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 15:56:55 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/06 18:09:13 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
 * HAS TO DIRECTLY OPEN, DUP AND PIPE FD ! NO STOCKING THEN (OPEN, DUP, PIPE)ING !
 */

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

static void		do_append(t_redir_manager *m, int fd, int *j)
{
	if (fd == '&' - '0')
	{
		m->is_append[0] = 1;
		m->is_append[1] = 1;
	}
	else
		m->is_append[fd] = 1;
	(*j)++;
}

static int		do_open_file(t_redir_manager *m, char *cmd, int fd)
{
	int		tmpfd;

	/*
	** HAS TO PARSE THIS (DQUOTE, SQUOTE)
	**/
	if ((tmpfd = open(cmd[i + 1])) == -1)
		return (0);
	if (fd == '&' - '0')
	{
		m->to_redir[0] = tmpfd;
		m->to_redir[1] = tmpfd;
	}
	else
		m->to_redir[fd] = tmpfd;
	return (1);
}

static int		operate_redir_out(t_redir_manager *m, char **cmd, size_t i)
{
	int		fd;
	int		j;

	fd = 1;
	j = 0;
	if (cmd[i][j] != '>')
		fd = cmd[i][j++] - '0';
	if (cmd[i][j] == '>' && cmd[i][j + 1] == '>')
		do_append(m, fd, &j);
	j++;
	if (cmd[i][j] == '&' && cmd[i][j + 1] == '-')
		m->closed[fd] = 1;
	else if (cmd[i][j] == '&' && ft_isdigit(cmd[i][j + 1]))
	{
		m->do_redir[fd] = 1;
		m->to_redir[fd] = cmd[i][j + 1] - '0';
	}
	else
		return (do_open_file(m, cmd, fd));
	return (1);
}

static void		operate_redir_out(t_redir_manager *m, char **cmd, size_t i)
{
	//mdr;
}

void			command_split_redirs(t_env *env, char **cmd, int pipe_type)
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
			if (!(operate_redir_out(&m, cmd, i)))
				return (0);
		}
		else if (cmd[i][0] == '<' || (ft_isdigit(cmd[i][0]) && cmd[i][1] == '<'))
		{
			has_redired = 1;
			if (!(operate_redir_in(&m, cmd, i)))
				return (0);
		}
		else if (has_redired)
			command_run_piped(env, sub, pipe_type);
		else
			command_split_push(&sub, cmd[i]);
		i++;
	}
	return (1);
}
