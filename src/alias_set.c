/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:13:53 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 23:12:58 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	alias_set(t_env *env, char *alias, char *cmd)
{
	t_alias_list	*lst;

	lst = env->aliases;
	while (lst)
	{
		if (!ft_strcmp(lst->alias.alias, alias))
		{
			lst->alias.cmd = cmd;
			return ;
		}
		lst = lst->next;
	}
	alias_create(env, alias, cmd);
}
