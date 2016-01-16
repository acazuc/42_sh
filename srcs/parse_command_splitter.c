/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_splitter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 17:34:45 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/16 18:56:00 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		add_param(char ***tab, char *str)
{
	char	**new_tab;
	int		len;

	len = 0;
	while ((*tab)[len])
		len++;
	if (!(new_tab = malloc(sizeof(*new_tab) * (len + 2))))
		error_quit("Failed to malloc new cmd arg tab");
	len = 0;
	while ((*tab)[len])
	{
		new_tab[len] = (*tab)[len];
		len++;
	}
	new_tab[len++] = str;
	new_tab[len++] = NULL;
	free(*tab);
	*tab = new_tab;
}

static void		check_quotes_parenthesis(t_parser *parser, int i)
{
	if (parser->cmd[i] == '\'' && (i == 0 || parser->cmd[i - 1] != '\\')
		&& !(parser->in_dquote) && !(parser->p_count))
		parser->in_squote = !(parser->in_squote);
	if (parser->cmd[i] == '\"' && (i == 0 || parser->cmd[i - 1] != '\\')
		&& !(parser->in_squote) && !(parser->p_count))
		parser->in_dquote = !(parser->in_dquote);
	if (parser->cmd[i] == '(' && (i == 0 || parser->cmd[i - 1] != '\\')
		&& !(parser->in_squote) && !(parser->in_dquote))
		parser->p_count++;
	if (parser->cmd[i] == ')' && (i == 0 || parser->cmd[i - 1] != '\\')
		&& !(parser->in_squote) && !(parser->in_dquote))
		parser->p_count--;

}

static void		check_split(t_parser *parser, int i, int *start, char *split)
{
	char		*arg;

	if (ft_strstr(parser->cmd + i, split) == parser->cmd + i
		&& (i == 0 || parser->cmd[i - 1] != '\\')
		&& !(parser->in_squote) && !(parser->in_dquote) && !(parser->p_count))
	{
		if (!(arg = ft_strsub(parser->cmd, *start, i - *start)))
			error_quit("Failed to malloc new cmd arg");
		add_param(&(parser->result), arg);
		*start = i + 1;
	}
}

char			**parse_command_splitter(char *cmd, char *split)
{
	t_parser	parser;
	char		*arg;
	int			start;
	int			i;

	if (!(parser.result = malloc(sizeof(*(parser.result)))))
		error_quit("Failed to malloc parser split");
	(parser.result)[0] = NULL;
	parser.cmd = cmd;
	i = 0;
	while ((parser.cmd)[i])
	{
		start = i;
		parser.in_dquote = 0;
		parser.in_squote = 0;
		parser.p_count = 0;
		while (cmd[i] && (parser.p_count || parser.in_dquote || parser.in_squote))
		{
			check_quotes_parenthesis(&parser, i);
			check_split(&parser, i, &start, split);
		}
		if (!(arg = ft_strsub(cmd, start, i - start)))
			error_quit("Failed to malloc new cmd args");
		add_param(&(parser.result), arg);
	}
	return (parser.result);
}
