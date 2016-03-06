/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_cmd_missing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 13:16:10 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/06 14:32:14 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		simplify(t_line_parser *p)
{
	ssize_t	i;
	char	*s;
	char	*tmp;

	s = p->result;
	i = 0;
	while (s[i])
	{
		if ((s[i] == '[' && s[i + 1] == ']')
				|| (s[i] == '{' && s[i + 1] == '}')
				|| (s[i] == '(' && s[i + 1] == ')')
				|| (s[i] == '\'' && s[i + 1] == '\'')
				|| (s[i] == '"' && s[i + 1] == '"')
				|| (s[i] == '`' && s[i + 1] == '`'))
		{
			if (!(tmp = ft_memalloc(sizeof(*tmp) * (ft_strlen(s) - 2 + 1))))
				ERROR("Failed to malloc tmp");
			t_strcat(ft_strncat(tmp, s, i), s + i + 2);
			free(s);
			s = tmp;
			i -= 2;
		}
		i++;
	}
	p->result = s;
}

static void		append(t_line_parser *p, char c)
{
	char	tmp[2];

	tmp[0] = c;
	tmp[1] = '\0';
	if (!(p->result = ft_strjoin_free1(p->result, &(tmp[0]))))
		ERROR("Failed to append");
}

static void		check_parser(t_line_parser *p, char *str, size_t i)
{
	if (i != 0 && (get_bs_nb_before(str, i) % 2))
		return ;
	if (str[i] == '"' && !p->squote)
	{
		append(p, '"');
		p->dquote = !p->dquote;
	}
	if (str[i] == '\'' && !p->dquote)
	{
		append(p, '\'');
		p->squote = !p->squote;
	}
	if (!p->dquote && !p->squote)
	{
		if (str[i] == '`' || str[i] == '[' || str[i] == ']' || str[i] == '{'
				|| str[i] == '}' || str[i] == '(' || str[i] == ')')
			append(p, str[i]);
	}
}

static void		parser_init(t_line_parser *p)
{
	if (!(p->result = malloc(sizeof(*p->result))))
		ERROR("Failed to malloc string");
	p->result[0] = '\0';
	p->dquote = 0;
	p->squote = 0;
}

char			get_next_cmd_missing(char *str)
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
	simplify(&p);
	if (!p.result[0])
		return ('\0');
	return (p.result[ft_strlen(p.result) - 1]);
}
