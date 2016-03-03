/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_push_param.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 13:28:13 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/03 11:35:09 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	parse_command_add_param(char ***tab, char *str)
{
	char	**new_tab;
	int		len;

	len = 0;
	while ((*tab)[len])
		len++;
	if (!(new_tab = malloc(sizeof(*new_tab) * (len + 2))))
		ERROR("Failed to malloc new cmd arg");
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

void		parse_command_push_param(t_parser *p)
{
	char	*arg;

	if (p->start >= p->i)
		return ;
	if (!(arg = ft_strsub(p->cmd, p->start, p->i - p->start)))
		ERROR("Faild to malloc new cmd arg");
	parse_command_add_param(&(p->result), arg);
}
