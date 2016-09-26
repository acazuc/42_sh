/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_replace_alias.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:33:29 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/26 17:32:06 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int		tab_len(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		++i;
	return (i);
}

static void		push_rep(char **new, int *c, char **rep, int rep_len)
{
	int		j;

	j = 0;
	while (j < rep_len)
	{
		if (!(new[(*c)++] = ft_strdup(rep[j])))
			ERROR("strdup failed");
		j++;
	}
}

static void		push_alias(char ***cmd, int i, char **rep)
{
	char	**new;
	int		rep_len;
	int		cmd_len;
	int		c;
	int		k;

	cmd_len = tab_len(*cmd);
	rep_len = tab_len(rep);
	if (!(new = malloc(sizeof(*new) * (cmd_len + rep_len))))
		ERROR("malloc failed");
	c = 0;
	k = 1;
	while (c < cmd_len + rep_len)
	{
		if (c == i)
		{
			free((*cmd)[i]);
			push_rep(new, &c, rep, rep_len);
			continue;
		}
		new[c++] = (*cmd)[k++];
	}
	new[c] = NULL;
	free(*cmd);
	*cmd = new;
}

static int		replace_alias(t_env *env, char ***cmd, int i)
{
	t_alias_list	*lst;

	lst = env->aliases;
	while (lst)
	{
		if (!lst->alias.passed && !ft_strcmp((*cmd)[i], lst->alias.alias))
		{
			lst->alias.passed = 1;
			push_alias(cmd, i, lst->alias.cmd);
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

void			command_replace_alias(t_env *env, char ***cmd)
{
	int		replaced;
	int		i;

	i = 0;
	replaced = 1;
	while (replaced)
	{
		replaced = 0;
		while ((*cmd)[i])
		{
			if (i == 0 || !ft_strcmp((*cmd)[i], "|") || !ft_strcmp((*cmd)[i], ";"))
			{
				replaced |= replace_alias(env, cmd, i);
			}
			++i;
		}
	}
	alias_clean_passed(env);
}
