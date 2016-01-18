/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_params.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 11:16:52 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/18 16:36:05 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char		*remove_quotes(char *str)
{
	char	*result;
	int		len;

	len = ft_strlen(str);
	if (str[0] == '\'' && str[len - 1] == '\'')
	{
		if (!(result = ft_strsub(str, 1, len - 2)))
			error_quit("Failed to malloc removed quote param");
	}
	else if (str[0] == '"' && str[len - 1] == '"')
	{
		if (!(result = ft_strsub(str, 1, len - 2)))
			error_quit("Failed to malloc removed quote param");
	}
	else
	{
		if (!(result = ft_strdup(str)))
			error_quit("Failed to malloc removed quote param");
	}
	return (result);
}

static char		*remove_backslashs(char *str)
{
	size_t	i;
	char	*sub_1;
	char	*sub_2;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\')
		{
			if (!(sub_1 = ft_strsub(str, 0, i)))
				error_quit("Failed to malloc parsing part");
			if (!(sub_2 = ft_strsub(str, i + 1, ft_strlen(str) - i - 1)))
				error_quit("Failed to malloc parsing part");
			free(str);
			if (!(str = ft_strjoin_free3(sub_1, sub_2)))
				error_quit("Failed to malloc parsing part");
		}
		i++;
	}
	return (str);
}

static void		add_param(char ***tab, char *str)
{
	char	**new_tab;
	int		len;

	len = 0;
	while ((*tab)[len])
		len++;
	if (!(new_tab = malloc(sizeof(*new_tab) * (len + 2))))
		error_quit("Failed to malloc new cmd args tab");
	len = 0;
	while ((*tab)[len])
	{
		new_tab[len] = (*tab)[len];
		len++;
	}
	str = replace_tilde_home(str);
	str = remove_quotes(str);
	str = remove_backslashs(str);
	new_tab[len++] = str;
	new_tab[len++] = NULL;
	free(*tab);
	*tab = new_tab;
}

char	**parse_command_params(char *cmd)
{
	char	**result;
	char	*arg;
	int		in_dquote;
	int		in_squote;
	int		start;
	int		i;

	if (!(result = malloc(sizeof(*result))))
		error_quit("Failed to malloc cmd args tab");
	result[0] = NULL;
	i = 0;
	while (cmd[i])
	{
		while (cmd[i] && cmd[i] == ' ')
			i++;
		if (!cmd[i])
			return (result);
		start = i;
		in_dquote = 0;
		in_squote = 0;
		while (cmd[i] && (in_dquote || in_squote || cmd[i] != ' '))
		{
			if (cmd[i] == '\'' && (i == 0 || cmd[i - 1] != '\\') && !in_dquote)
				in_squote = !in_squote;
			if (cmd[i] == '"' && (i == 0 || cmd[i - 1] != '\\') && !in_squote)
				in_dquote = !in_dquote;
			i++;
		}
		if (!(arg = ft_strsub(cmd, start, i - start)))
			error_quit("Failed to malloc new cmd arg");
		add_param(&result, arg);
	}
	return (result);
}
