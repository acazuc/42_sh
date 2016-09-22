/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_empty.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 12:45:56 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/03 13:42:14 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	parse_command_empty(char ***cmd)
{
	char	**new;
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	while ((*cmd)[i])
	{
		if (ft_strcmp((*cmd)[i], ""))
			size++;
		i++;
	}
	if (!(new = malloc(sizeof(*new) * (size + 1))))
		ERROR("Failed to malloc new tab");
	i = 0;
	size = 0;
	while ((*cmd)[i])
	{
		if (ft_strcmp((*cmd)[i], ""))
			new[size++] = (*cmd)[i];
		i++;
	}
	free(*cmd);
	new[size] = NULL;
	*cmd = new;
}
