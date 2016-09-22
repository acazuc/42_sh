/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias_exists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:08:27 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 23:13:10 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		alias_exists(t_env *env, char *alias)
{
	t_alias_list	*lst;

	lst = env->aliases;
	while (lst)
	{
		if (!ft_strcmp(lst->alias.alias, alias))
			return (1);
	}
	return (0);
}
