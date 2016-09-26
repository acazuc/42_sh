/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 17:48:28 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/26 17:19:19 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	alias_create(t_env *env, char *alias, char *cmd)
{
	t_alias_list	*new;

	if (!(new = malloc(sizeof(*new))))
		ERROR("Failed to create alias");
	if (!(new->alias.alias = ft_strdup(alias)))
		ERROR("Failed to duplicate alias key");
	if (!(cmd = ft_strdup(cmd)))
		ERROR("strdup failed");
	cmd = ft_strtrim_free(cmd);
	cmd = parse_command_short(cmd);
	new->alias.cmd = parse_command_split(cmd);
	free(cmd);
	new->alias.passed = 0;
	new->next = env->aliases;
	env->aliases = new;
}
