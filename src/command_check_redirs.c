/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_check_redirs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 16:54:43 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/26 18:12:34 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	is_redir(char *arg)
{
	if ((arg[0] == '<' || arg[0] == '>')
			|| ((arg[0] == '&' || ft_isdigit(arg[0]))
				&& (arg[1] == '<' || arg[1] == '>')))
	{
		if (ft_strstr(arg, ">&-") == arg || ft_strstr(arg, ">&-") == arg + 1)
			return (0);
		return (1);
	}
	return (0);
}

int			command_check_redirs(char **args)
{
	size_t		i;

	i = 0;
	while (args[i])
	{
		if (is_redir(args[i]))
		{
			if (!args[i + 1] || is_redir(args[i + 1])
					|| ft_strstr(args[i], "&>&") == args[i]
					|| ft_strstr(args[i], "&>>&") == args[i])
			{
				ft_putstr_fd("cash: parse error near ", 2);
				if (ft_isdigit(args[i][0]))
					ft_putchar_fd(args[i][1], 2);
				else
					ft_putchar_fd(args[i][0], 2);
				ft_putchar_fd('\n', 2);
				return (0);
			}
		}
		i++;
	}
	return (1);
}
