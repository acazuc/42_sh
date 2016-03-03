/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_unquote.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 12:43:05 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/03 13:09:38 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		free_join(char **cmd, char *sub1, char *sub2, char *sub3)
{
	free(*cmd);
	if (!(*cmd = ft_strjoin_free3(sub1, sub2)))
		ERROR("Failed to join subbed quotes removing 1");
	if (!(*cmd = ft_strjoin_free3(*cmd, sub3)))
		ERROR("Failed to join subbed quotes removing 2");
}

static void		get_sub1(char **sub, char *cmd, size_t i)
{
	if (!(*sub = ft_strsub(cmd, 0, i)))
		ERROR("Failed to sub quotes removing 1");
}

static void		get_sub2(char **sub, char *cmd, char *next_occur, size_t i)
{
	if (!(*sub = ft_strsub(cmd, i + 1
					, (size_t)(next_occur - cmd) - i - 1)))
		ERROR("Failed to sub quotes removing 2");
}

static char		*remove_quotes(char *cmd)
{
	size_t	i;
	char	*next_occur;
	char	*sub1;
	char	*sub2;
	char	*sub3;

	i = 0;
	while (cmd[i])
	{
		if ((cmd[i] == '"' || cmd[i] == '\'')
				&& (next_occur = ft_strchr(cmd + i + 1, cmd[i])))
		{
			get_sub1(&sub1, cmd, i);
			get_sub2(&sub2, cmd, next_occur, i);
			if (!(sub3 = ft_strsub(next_occur + 1
							, 0, ft_strlen(next_occur + 1))))
				ERROR("Failed to sub quotes removing 3");
			i = (size_t)(next_occur - cmd) - 1;
			free_join(&cmd, sub1, sub2, sub3);
		}
		i++;
	}
	return (cmd);
}

void			parse_command_unquote(char **cmd)
{
	size_t	i;

	i = 0;
	while (cmd[i])
	{
		cmd[i] = remove_quotes(cmd[i]);
		i++;
	}
}
