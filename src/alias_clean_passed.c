/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias_clean_passed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 17:13:13 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/26 17:13:40 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		alias_clean_passed(t_env *env)
{
	t_alias_list	*lst;

	lst = env->aliases;
	while (lst)
	{
		lst->alias.passed = 0;
		lst = lst->next;
	}
}
