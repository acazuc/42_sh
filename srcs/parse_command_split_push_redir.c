/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_split_push_redir.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 15:03:32 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/06 17:23:11 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			parse_command_split_push_redir(t_parser *p)
{
	if (p->i != p->start + 1 || (p->cmd[p->i - 1] != '&'
				&& !ft_isdigit(p->cmd[p->i - 1])))
	{
		if (p->i != p->start)
			parse_command_push_param(p);
		p->start = p->i;
	}
	if (p->cmd[p->i + 1] == p->cmd[p->i])
		p->i++;
	if (p->cmd[p->i + 1] == '&')
	{
		if (p->cmd[p->i + 2] == '-' || ft_isdigit(p->cmd[p->i + 2]))
			p->i += 2;
		else
			p->i++;
	}
	p->i++;
	parse_command_push_param(p);
	p->start = p->i;
}
