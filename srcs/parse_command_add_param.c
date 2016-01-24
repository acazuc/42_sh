/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_add_param.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 13:17:22 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/24 11:57:17 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	parse_command_add_param(char ***tab, char *str)
{
	char	**new_tab;
	int		len;

	len = 0;
	while ((*tab)[len])
		len++;
	if (!(new_tab = malloc(sizeof(*new_tab) * (len + 2))))
		error_quit("Failed to malloc new cmd arg");
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
