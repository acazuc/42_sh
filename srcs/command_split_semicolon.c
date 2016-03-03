/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_split_semicolon.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:40:00 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/03 14:39:41 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		sub_clear(char ***sub)
{
	if (!(*sub = malloc(sizeof(*sub))))
		ERROR("Failed to malloc sub command");
	(*sub)[0] = NULL;
}

static void		sub_push(char ***sub, char *add)
{
	size_t	i;
	char	**new;

	i = 0;
	while ((*sub)[i])
		i++;
	if (!(new = malloc(sizeof(*new) * (i + 2))))
		ERROR("Failed to malloc sub command");
	i = 0;
	while ((*sub)[i])
	{
		new[i] = (*sub)[i];
		i++;
	}
	new[i++] = add;
	new[i++] = NULL;
	free(*sub);
	*sub = new;
}

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
			sub_clear(&sub);
		}
		else
			sub_push(&sub, cmd[i]);
		i++;
	}
	if (sub[0])
		command_split_pipe(env, sub);
	free(cmd);
}
