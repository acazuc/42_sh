/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_host_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 16:18:19 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/03 11:31:00 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*get_host_name(void)
{
	char	host_name[256];
	char	*ret;
	int		i;

	i = 0;
	while (i < 256)
		host_name[i++] = 0;
	gethostname(host_name, 256);
	i = 0;
	while (i < 256 && host_name[i])
		i++;
	if (!(ret = malloc(sizeof(*ret) * (i + 1))))
		ERROR("Failed to nalloc host name");
	i = 0;
	while (host_name[i])
	{
		ret[i] = host_name[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
