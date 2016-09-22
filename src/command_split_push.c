/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_split_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 15:59:58 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/06 16:00:58 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		command_split_push(char ***sub, char *add)
{
	size_t	i;
	char	**new;

	i = 0;
	while ((*sub)[i])
		i++;
	if (!(new = malloc(sizeof(*new) * (i + 2))))
		ERROR("Failed to malloc sub command");
	i = 0;
	while ((*sub)[i])
	{
		new[i] = (*sub)[i];
		i++;
	}
	new[i++] = add;
	new[i++] = NULL;
	free(*sub);
	*sub = new;
}
