/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:17:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/26 17:32:28 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char		**get_parsed(char **str)
{
	char	**parsed;

	if (!(*str = ft_strdup(*str)))
		ERROR("strdup failed");
	*str = ft_strtrim_free(*str);
	*str = parse_command_short(*str);
	parsed = parse_command_split(*str);
	return (parsed);
}

static void		do_clear(char **parsed, char *str)
{
	int		i;

	i = 0;
	while (parsed[i])
	{
		free(parsed[i]);
		++i;
	}
	free(parsed);
	free(str);
}

void			command_execute(t_env *env, char *str)
{
	char	**parsed;

	parsed = get_parsed(&str);
	command_replace_alias(env, &parsed);
	if (command_check_pipes(parsed) && command_check_redirs(parsed))
		command_split_semicolon(env, parsed);
	do_clear(parsed, str);
}
