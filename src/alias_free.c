/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 17:55:57 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/26 16:38:49 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	alias_free(t_alias_list *alias)
{
	int		i;

	i = 0;
	while (alias->alias.cmd[i])
	{
		free(alias->alias.cmd[i]);
		++i;
	}
	free(alias->alias.alias);
	free(alias->alias.cmd);
	free(alias);
}
