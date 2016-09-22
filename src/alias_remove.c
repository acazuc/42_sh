/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 17:53:56 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 23:12:08 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		alias_remove(t_env *env, char *alias)
{
	t_alias_list	*prv;
	t_alias_list	*lst;

	lst = env->aliases;
	prv = NULL;
	while (lst)
	{
		if (!ft_strcmp(lst->alias.alias, alias))
		{
			if (!prv)
				env->aliases = lst->next;
			else
				prv->next = lst->next;
			alias_free(lst);
			return (1);
		}
		prv = lst;
		lst = lst->next;
	}
	return (0);
}
