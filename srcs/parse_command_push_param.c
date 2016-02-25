/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_push_param.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 13:28:13 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/25 11:08:02 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	parse_command_push_param(t_parser *p)
{
	char	*arg;

	if (p->start >= p->i)
		return ;
	if (!(arg = ft_strsub(p->cmd, p->start, p->i - p->start)))
		error_quit("Faild to malloc new cmd arg");
	parse_command_add_param(&(p->result), arg);
}
