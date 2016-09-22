/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_home_with_tilde.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:00:01 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 15:07:27 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char		*get_home_with_tilde(t_env *env, char *cwd)
{
	char	*after_home;
	char	*home;

	home = get_home_directory(env);
	if (ft_strstr(cwd, home) != cwd)
	{
		free(home);
		return (cwd);
	}
	if (!(after_home = ft_strsub(cwd, ft_strlen(home)
					, ft_strlen(cwd) - ft_strlen(home))))
		ERROR("Failed to malloc PS1");
	free(cwd);
	free(home);
	if (!(cwd = ft_strjoin_free2("~", after_home)))
		ERROR("Failed to malloc PS1");
	return (cwd);
}
