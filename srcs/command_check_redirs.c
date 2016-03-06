/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_check_redirs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 16:54:43 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/06 17:30:40 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	is_redir(char *arg)
{
	return ((arg[0] == '<' || arg[0] == '>')
			|| ((args[0][0] == '&' || ft_isdigit(arg[0]))
				&& (arg[1] == '<' || arg[1] == '>')));

}

int		command_check_redirs(char **args)
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
				ft_putstr("cash: parse error near ");
				if (ft_isdigit(args[i][0]))
					ft_putchar(args[i][1]);
				else
					ft_putchar(args[i][0]);
				ft_putchar('\n');
				return (0);
			}
		}
		i++;
	}
	return (1);
}
