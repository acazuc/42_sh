/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_short.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:04:29 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/24 17:26:08 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*parse_command_short(char *cmd)
{
	size_t	start;
	size_t	i;
	char	*result;
	char	*tmp;
	int		in_dquote;
	int		in_squote;

	if (!(result = malloc(sizeof(*result))))
		error_quit("Failed to malloc short cmd");
	result[0] = '\0';
	in_dquote = 0;
	in_squote = 0;
	i = 0;
	while (cmd[i])
	{
		while (cmd[i] && (cmd[i] == ' ' || cmd[i] == '\t'))
			i++;
		if (!cmd[i])
			return (result);
		start = i;
		while (cmd[i] && (in_squote || in_dquote || (cmd[i] != ' ' && cmd[i] != '\t')))
		{
			if (cmd[i] == '\'' && !in_dquote)
				in_squote = !in_squote;
			if (cmd[i] == '\"' && !in_squote)
				in_dquote = !in_dquote;
			i++;
		}
		if (!(tmp = ft_strsub(cmd, start, i - start)))
			error_quit("Failed to sub short cmd");
		if (!(tmp = ft_strjoin_free1(tmp, " ")))
			error_quit("Failed to sub short cmd");
		if (!(result = ft_strjoin_free3(result, tmp)))
			error_quit("Failed to sub short cmd");
	}
	if (!(result = ft_strsub(result, 0, ft_strlen(result) - 1)))
		error_quit("Failed to sub short cmd");
	free(cmd);
	return (result);
}
