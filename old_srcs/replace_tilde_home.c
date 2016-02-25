/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_tilde_home.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 08:33:32 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/23 11:44:24 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char		*replace_tilde_home(t_env *env, char *str)
{
	char	*home_dir;
	char	*result;
	char	*sub;

	if (str[0] != '~')
		result = ft_strdup(str);
	else if (str[1] == '\0')
	{
		if (!(result = get_home_directory(env)))
			error_quit("Failed to malloc home dir");
	}
	else if (str[1] == '/')
	{
		if (!(home_dir = get_home_directory(env)))
			error_quit("Failed to malloc home dir");
		if (!(sub = ft_strsub(str, 1, ft_strlen(str) - 1)))
			error_quit("Failed to malloc home sub");
		if (!(result = ft_strjoin_free3(home_dir, sub)))
			error_quit("Failed to malloc home param");
	}
	else
		result = ft_strdup(str);
	free(str);
	return (result);
}
