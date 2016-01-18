/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_host_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 16:18:19 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/18 10:44:35 by acazuc           ###   ########.fr       */
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
	while (host_name[i])
		i++;
	if (!(ret = malloc(sizeof(*ret) * (i + 1))))
		error_quit("Failed to nalloc host name");
	i = 0;
	while (host_name[i])
	{
		ret[i] = host_name[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
