/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 13:58:22 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/04 15:22:08 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		check_parser(t_line_parser *p, char *str, size_t i)
{
	if (i != 0 && str[i - 1] == '\\')
		return ;
	if (str[i] == '"' && !p->squote && !p->bquote)
		p->dquote = !p->dquote;
	if (str[i] == '\'' && !p->dquote && !p->bquote)
		p->squote = !p->squote;
	if (str[i] == '`' && !p->dquote && !p->squote)
		p->bquote = !p->bquote;
	if (str[i] == '[' && !p->dquote && !p->squote && !p->bquote)
		p->bracket++;
	if (str[i] == ']' && !p->dquote && !p->squote && !p->bquote)
		p->bracket--;
	if (str[i] == '{' && !p->dquote && !p->squote && !p->bquote)
		p->cursh++;
	if (str[i] == '}' && !p->dquote && !p->squote && !p->bquote)
		p->cursh--;
	if (str[i] == '(' && !p->dquote && !p->squote && !p->bquote)
		p->subsh++;
	if (str[i] == ')' && !p->dquote && !p->squote && !p->bquote)
		p->subsh--;
}

static void		parser_init(t_line_parser *p)
{
	p->dquote = 0;
	p->squote = 0;
	p->bquote = 0;
	p->subsh = 0;
	p->bracket = 0;
	p->cursh = 0;
}

static char		get_missing_close(char *str)
{
	t_line_parser	p;
	size_t			i;

	parser_init(&p);
	i = 0;
	while (str[i])
	{
		check_parser(&p, str, i);
		i++;
	}
	if (p.dquote)
		return ('"');
	if (p.squote)
		return ('\'');
	if (p.bquote)
		return ('`');
	if (p.bracket)
		return ('[');
	if (p.cursh)
		return ('{');
	if (p.subsh)
		return ('(');
	return ('\0');
}

static void		print_missing_msg(char c)
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
}

char			*get_next_cmd(void)
{
	char	*next_line;
	char	*tmp;
	char	missing;

	missing = 'a';
	if (!(next_line = malloc(sizeof(*next_line))))
		ERROR("Failed to malloc line");
	next_line[0] = '\0';
	while (missing)
	{
		if (!(tmp = read_next_line()))
			ERROR("Failed to read line");
		if (!(next_line = ft_strjoin_free3(next_line, tmp)))
			ERROR("Failed to join lines");
		missing = get_missing_close(next_line);
		if (!missing)
			return (next_line);
		if (missing != 'a')
			if (!(next_line = ft_strjoin_free1(next_line, "\n")))
				ERROR("Failed to append \\n to next_line");
		print_missing_msg(missing);
	}
	return (next_line);
}
