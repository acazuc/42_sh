/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 17:53:56 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/24 17:57:15 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	alias_remove(t_env *env, char *alias)
{
	t_alias_list	*prv;
	t_alias_list	*lst;

	lst = env->aliases;
	prv = NULL;
	while (lst)
	{
		if (!ft_strcmp(lst->alias->alias, alias))
		{
			if (!prv)
				env->aliases = lst->next;
			else
				prv->next = lst->next;
			alias_free(lst);
			return ;
		}
		prv = lst;
		lst = lst->next;
	}
}
