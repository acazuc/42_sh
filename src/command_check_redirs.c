/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_check_redirs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 16:54:43 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/26 19:53:16 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	is_invalid_redir(char *arg, char *narg)
{
	char	org;
	int		i;

	i = 1;
	if (arg[0] == '>' || arg[0] == '<')
		org = arg[0];
	else if ((arg[1] == '>' || arg[1] == '<') && (ft_isdigit(arg[0])
				|| (arg[1] == '>' && arg[0] == '&')) && (org = arg[1]))
		i++;
	else
		return (0);
	if (arg[i + 1] == arg[i])
		i++;
	if (arg[i] == '&')
	{
		i++;
		if (arg[0] == '&' || (!ft_isdigit(arg[i]) && arg[i] != '-'))
			return (1);
	}
	else if (!narg)
		return (1);
	return (0);
}

int			command_check_redirs(char **args)
{
	size_t		i;

	i = 0;
	while (args[i])
	{
		if (is_invalid_redir(args[i], args[i + 1]))
		{
			ft_putstr_fd("cash: parse error near ", 2);
			if (ft_isdigit(args[i][0]))
				ft_putchar_fd(args[i][1], 2);
			else
				ft_putchar_fd(args[i][0], 2);
			ft_putchar_fd('\n', 2);
			return (0);
		}
		i++;
	}
	return (1);
}
