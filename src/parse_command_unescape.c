/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_unescape.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 12:50:15 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/06 12:50:50 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*parse_command_unescape(char *var)
{
	size_t	i;
	char	*tmp1;
	char	*tmp2;

	i = 0;
	while (var[i])
	{
		if ((var[i] == '\'' || var[i] == '"' || var[i] == '$')
				&& (i == 0 || !(get_bs_nb_before(var, i) % 2)))
		{
			if (!(tmp1 = ft_strsub(var, 0, i)))
				ERROR("Failed to sub");
			if (!(tmp1 = ft_strjoin_free1(tmp1, "\\")))
				ERROR("Failed to join");
			if (!(tmp2 = ft_strsub(var, i, ft_strlen(var) - i)))
				ERROR("Failed to sub");
			free(var);
			if (!(var = ft_strjoin_free3(tmp1, tmp2)))
				ERROR("Failed to sub");
		}
		i++;
	}
	return (var);
}
