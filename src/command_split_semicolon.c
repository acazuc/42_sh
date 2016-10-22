/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_split_semicolon.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:40:00 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/22 14:29:46 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			command_split_semicolon(t_env *env, char **cmd)
{
	size_t	i;
	char	**sub;

	i = 0;
	if (!(sub = malloc(sizeof(*sub))))
		ERROR("Failed to malloc split sub");
	sub[0] = NULL;
	while (cmd[i])
	{
		if (!ft_strcmp(cmd[i], ";"))
		{
			command_split_pipe(env, sub);
			command_split_clear(&sub);
		}
		else
			command_split_push(&sub, cmd[i]);
		i++;
	}
	if (sub[0])
		command_split_pipe(env, sub);
}
