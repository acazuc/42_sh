/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 17:48:28 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/03 11:33:52 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	alias_create(t_env *env, char *alias, char *cmd)
{
	t_alias_list	*new;

	if (!(new = malloc(sizeof(*new))))
		ERROR("Failed to create alias");
	if (!(new->alias = malloc(sizeof(*alias))))
		ERROR("Failed to create alias");
	new->alias->alias = alias;
	new->alias->cmd = cmd;
	new->next = env->aliases;
	env->aliases = new;
}
