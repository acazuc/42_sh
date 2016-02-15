/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:51:33 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/15 10:17:34 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		parse_line(t_env *env, char *cmd)
{
	char	**datas;
	int		i;

	datas = parse_command_semicolon(cmd);
	i = 0;
	while (datas[i])
		command_run_redirs(env, datas[i++]);
	free(cmd);
	free(datas);
}
