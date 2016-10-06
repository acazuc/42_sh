/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_tilde.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:34:46 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/06 21:46:10 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char		*parse_arg_tilde(t_env *env, char *arg)
{
	char	*home_dir;
	char	*result;
	char	*sub;

	if (arg[0] != '~')
		result = ft_strdup(arg);
	else if (arg[1] == '\0')
	{
		if (!(result = get_home_directory(env)))
			ERROR("Failed to malloc home dir");
	}
	else if (arg[1] == '/')
	{
		if (!(home_dir = get_home_directory(env)))
			ERROR("Failed to malloc home dir");
		if (!(sub = ft_strsub(arg, 1, ft_strlen(arg) - 1)))
			ERROR("Failed to malloc home sub");
		if (!(result = ft_strjoin_free3(home_dir, sub)))
			ERROR("Failed to malloc home param");
	}
	else
		result = ft_strdup(arg);
	return (result);
}

void			parse_command_tilde(t_env *env, char **cmd)
{
	size_t	i;

	i = 0;
	while (cmd[i])
	{
		cmd[i] = parse_arg_tilde(env, cmd[i]);
		i++;
	}
}
