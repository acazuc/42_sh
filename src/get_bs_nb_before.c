/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bs_nb_before.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 17:01:32 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/04 17:04:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		get_bs_nb_before(char *str, size_t i)
{
	int		bs_count;

	bs_count = 0;
	if (i == 0)
		return (0);
	i--;
	while (str[i] == '\\')
	{
		bs_count++;
		if (i == 0)
			return (bs_count);
		i--;
	}
	return (bs_count);
}
