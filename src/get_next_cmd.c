/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 13:58:22 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 15:16:01 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int		print_missing_msg(char c)
{
	if (c == '"')
		ft_putstr("dquote> ");
	else if (c == '\'')
		ft_putstr("squote> ");
	else if (c == '`')
		ft_putstr("bquote> ");
	else if (c == '(')
		ft_putstr("subsh> ");
	else if (c == '[')
		ft_putstr("bracket> ");
	else if (c == '{')
		ft_putstr("cursh> ");
	else
	{
		ft_putendl("parse error");
		return (0);
	}
	return (1);
}

static void		init(char **next_line, char *missing)
{
	*missing = 'a';
	if (!(*next_line = malloc(sizeof(**next_line))))
		ERROR("Failed to malloc line");
	(*next_line)[0] = '\0';
}

char			*get_next_cmd(void)
{
	char	*next_line;
	char	*tmp;
	char	missing;

	init(&next_line, &missing);
	while (missing)
	{
		if (!(tmp = read_next_line(1)))
			ERROR("Failed to read line");
		if (!(next_line = ft_strjoin_free3(next_line, tmp)))
			ERROR("Failed to join lines");
		missing = get_next_cmd_missing(next_line);
		if (!missing)
			return (next_line);
		if (missing != 'a')
			if (!(next_line = ft_strjoin_free1(next_line, "\n")))
				ERROR("Failed to append \\n to next_line");
		if (!(print_missing_msg(missing)))
		{
			free(next_line);
			return (NULL);
		}
	}
	return (next_line);
}
