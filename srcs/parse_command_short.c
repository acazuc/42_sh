/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_short.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:04:29 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/25 12:46:48 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		check_cmd_quotes(t_parser *p)
{
	while (p->cmd[p->i] && (p->in_squote || p->in_dquote
				|| (p->cmd[p->i] != ' ' && p->cmd[p->i] != '\t')))
	{
		if (p->cmd[p->i] == '\'' && !(p->in_dquote)
				&& (p->i == 0 || p->cmd[p->i - 1] != '\\'))
			p->in_squote = !(p->in_squote);
		if (p->cmd[p->i] == '\"' && !(p->in_squote)
				&& (p->i == 0 || p->cmd[p->i - 1] != '\\'))
			p->in_dquote = !(p->in_dquote);
		p->i++;
	}
}

static char		*add_value(t_parser *p, char *result)
{
	char	*tmp;

	if (!(tmp = ft_strsub(p->cmd, p->start, p->i - p->start)))
		error_quit("Failed to sub short cmd");
	if (!(tmp = ft_strjoin_free1(tmp, " ")))
		error_quit("Failed to sub short cmd");
	if (!(result = ft_strjoin_free3(result, tmp)))
		error_quit("Failed to sub short cmd");
	return (result);
}

static void		init(t_parser *p, char **result, char *cmd)
{
	if (!(*result = malloc(sizeof(**result))))
		error_quit("Failed to malloc short cmd");
	(*result)[0] = '\0';
	p->cmd = cmd;
	p->in_dquote = 0;
	p->in_squote = 0;
	p->i = 0;
}

char			*parse_command_short(char *cmd)
{
	t_parser	p;
	char		*result;

	init(&p, &result, cmd);
	while (cmd[p.i])
	{
		while (cmd[p.i] && (cmd[p.i] == ' ' || cmd[p.i] == '\t'))
			p.i++;
		if (!cmd[p.i])
			return (result);
		p.start = p.i;
		check_cmd_quotes(&p);
		result = add_value(&p, result);
	}
	if (ft_strlen(result) > 0
			&& !(result = ft_strsub_free(result, 0, ft_strlen(result) - 1)))
		error_quit("Failed to sub short cmd");
	free(cmd);
	return (result);
}
