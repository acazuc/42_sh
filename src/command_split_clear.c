/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_split_clear.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 16:05:21 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 22:59:49 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		command_split_clear(char ***sub)
{
	free(*sub);
	if (!(*sub = malloc(sizeof(*sub))))
		ERROR("Failed to malloc sub command");
	(*sub)[0] = NULL;
}
