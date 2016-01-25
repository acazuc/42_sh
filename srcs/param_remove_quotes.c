/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_remove_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 08:20:54 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/25 08:23:33 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*param_remove_quotes(char *str)
{
	char	*result;
	int		len;

	len = ft_strlen(str);
	if (str[0] == '\'' && str[len - 1] == '\'')
	{
		if (!(result = ft_strsub(str, 1, len - 2)))
			error_quit("Failed to remove quotes of param");
	}
	else if (str[0] == '"' && str[len - 1] == '"')
	{
		if (!(result = ft_strsub(str, 1, len - 2)))
			error_quit("Failed to remove quote of param");
	}
	else
	{
		if (!(result = ft_strdup(str)))
			error_quit("Failed to remove quote of param");
		}
	free(str);
	return (result);
}
