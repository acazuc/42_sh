/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_alias.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 18:03:01 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/26 17:20:05 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int		action_undo(char *equals, char tmp, char *msg)
{
	equals[0] = tmp;
	ft_putendl_fd(msg, 2);
	return (-1);
}

static int		action(t_env *env, char *value)
{
	char	*equals;
	char	*key;
	char	*val;
	char	tmp;

	equals = ft_strchr(value, '=');
	if (!equals)
		return (-1);
	key = value;
	val = equals + 1;
	tmp = equals[0];
	equals[0] = '\0';
	if (!ft_strlen(val))
		return (action_undo(equals, tmp, "cash: alias: invalid alias key"));
	if (!equals[1])
		return (action_undo(equals, tmp, "cash: alias: invalis alias value"));
	alias_set(env, key, val);
	equals[0] = tmp;
	return (1);
}

static void		print_alias_escaped(char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
			ft_putstr("\\\"");
		else if (str[i] == '\n')
			ft_putstr("\\n");
		else
			ft_putchar(str[i]);
		i++;
	}
}

static void		print_aliases(t_env *env)
{
	t_alias_list	*lst;
	int				i;

	lst = env->aliases;
	while (lst)
	{
		ft_putchar('"');
		print_alias_escaped(lst->alias.alias);
		ft_putstr("\"=\"");
		i = 0;
		while (lst->alias.cmd[i])
		{
			print_alias_escaped(lst->alias.cmd[i]);
			if (lst->alias.cmd[i + 1])
				ft_putchar(' ');
			++i;
		}
		ft_putstr("\"\n");
		lst = lst->next;
	}
}

int				builtin_alias(t_env *env, char **datas, int len)
{
	int		i;

	i = 1;
	if (len == 1)
	{
		print_aliases(env);
		return (1);
	}
	while (i < len)
	{
		if (action(env, datas[i]) == -1)
			return (-1);
		i++;
	}
	return (1);
}
