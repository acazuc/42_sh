/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:17:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/26 15:21:01 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	command_execute(t_env *env, char *str)
{
	char	**parsed;
	int		i;

	if (!(str = ft_strdup(str)))
		ERROR("strdup failed");
	str = ft_strtrim_free(str);
	str = parse_command_short(str);
	parsed = parse_command_split(str);
	free(str);
	if (command_check_pipes(parsed) && command_check_redirs(parsed))
		command_split_semicolon(env, parsed);
	i = 0;
	while (parsed[i])
	{
		free(parsed[i]);
		i++;
	}
	free(parsed);
}
