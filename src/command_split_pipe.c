/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_split_pipe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:47:27 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/07 14:22:33 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			command_split_pipe(t_env *env, char **cmd)
{
	size_t	i;
	char	**sub;
	int		was_pipe;

	was_pipe = 0;
	i = 0;
	if (!(sub = malloc(sizeof(*sub))))
		ERROR("Failed to malloc split sub");
	sub[0] = NULL;
	while (cmd[i])
	{
		if (!(ft_strcmp(cmd[i], "|")))
		{
			command_run_piped(env, sub, was_pipe ? PIPE_IO : PIPE_O);
			was_pipe = 1;
			command_split_clear(&sub);
		}
		else
			command_split_push(&sub, cmd[i]);
		i++;
	}
	command_run_piped(env, sub, was_pipe ? PIPE_I : PIPE_NO);
	free(cmd);
}
