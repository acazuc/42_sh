/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_split_redirs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 15:56:55 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 23:09:02 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		init(t_redir_manager *m, size_t *i, int *has_redired
		, char ***sub)
{
	int					j;

	j = 0;
	while (j < 10)
	{
		m->old_fd[j] = 0;
		m->closed[j] = 0;
		m->has_changed[j] = 0;
		j++;
	}
	*i = 0;
	*has_redired = 0;
	if (!(*sub = malloc(sizeof(**sub))))
		ERROR("Failed to malloc split sub");
	(*sub)[0] = NULL;
}

static int		command_split_test_out(t_redir_manager *m, char **cmd
		, size_t *i, int *has_redired)
{
	if (cmd[*i][0] == '>' || ((cmd[*i][0] == '&' || ft_isdigit(cmd[*i][0]))
				&& cmd[*i][1] == '>'))
	{
		*has_redired = 1;
		if (!(command_split_redirs_out(m, cmd, i)))
		{
			redir_reset(m);
			return (0);
		}
		return (-1);
	}
	return (1);
}

static int		command_split_test_in(t_redir_manager *m, char **cmd
		, size_t *i, int *has_redired)
{
	if (cmd[*i][0] == '<' || (ft_isdigit(cmd[*i][0]) && cmd[*i][1] == '<'))
	{
		*has_redired = 1;
		if (!command_split_redirs_in(m, cmd, i))
		{
			redir_reset(m);
			return (0);
		}
		return (-1);
	}
	return (1);
}

static int		command_split_end(t_env *env, char **sub
		, t_redir_manager *m)
{
	if (sub[0])
		command_run(env, sub);
	redir_reset(m);
	return (1);
}

int				command_split_redirs(t_env *env, char **cmd)
{
	t_redir_manager		m;
	size_t				i;
	char				**sub;
	int					has_redired;
	int					ret;

	init(&m, &i, &has_redired, &sub);
	while (cmd[i])
	{
		if (!(ret = command_split_test_out(&m, cmd, &i, &has_redired)))
			return (0);
		else if (ret != -1 && !(ret = command_split_test_in(&m, cmd, &i
						, &has_redired)))
			return (0);
		else if (ret != -1 && has_redired)
			command_run(env, sub);
		else if (ret != -1)
			command_split_push(&sub, cmd[i]);
		i++;
	}
	return (command_split_end(env, sub, &m));
}
