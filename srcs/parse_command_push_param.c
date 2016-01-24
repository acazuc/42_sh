/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_push_param.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 13:28:13 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/24 13:32:14 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	parse_command_push_param(char ***tab, char *cmd, int start, int i)
{
	char	*arg;

	if (!(arg = ft_strsub(cmd, start, i - start)))
		error_quit("Faild to malloc new cmd arg");
	parse_command_add_param(tab, arg);
}
