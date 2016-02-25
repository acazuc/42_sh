/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_split_pipe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:47:27 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/25 15:19:50 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		sub_clear(char ***sub)
{
	free(*sub);
	if (!(*sub = malloc(sizeof(*sub))))
		error_quit("Failed to malloc sub command");
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
		error_quit("Failed to malloc sub command");
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

void			command_split_pipe(t_env *env, char **cmd)
{
	size_t	i;
	char	**sub;
	int		was_pipe;

	was_pipe = 0;
	i = 0;
	if (!(sub = malloc(sizeof(*sub))))
		error_quit("Failed to malloc split sub");
	sub[0] = NULL;
	while (cmd[i])
	{
		if (!(ft_strcmp(cmd[i], "|")))
		{
			command_run_piped(env, sub, was_pipe ? PIPE_IO : PIPE_O);
			was_pipe = 1;
			sub_clear(&sub);
		}
		else
			sub_push(&sub, cmd[i]);
		i++;
	}
	if (sub[0])
		command_run_piped(env, sub, was_pipe ? PIPE_I : PIPE_NO);
	sub_clear(&sub);
	free(sub);
}
