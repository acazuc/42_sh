/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_remove_backslashs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 08:24:15 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/25 08:30:13 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*param_remove_backslashs(char *str)
{
	char	*sub_1;
	char	*sub_2;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\')
		{
			if (!(sub_1 = ft_strsub(str, 0, i)))
				error_quit("Failed to malloc backslash sub 1");
			if (!(sub_2 = ft_strsub(str, i + 1, ft_strlen(str) - i - 1)))
				error_quit("Failed to malloc backslash sub 2");
			free(str);
			if (!(str = ft_strjoin_free3(sub_1, sub_2)))
				error_quit("Failed to malloc backslash sub join");
		}
		i++;
	}
	return (str);
}
