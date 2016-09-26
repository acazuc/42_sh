/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_push_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 15:47:00 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/26 18:25:17 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char	*cmd_rebuild(char **cmd)
{
	char	*a;
	int		i;

	if (!(a = ft_strnew(0)))
		ERROR("ft_strnew failed");
	i = 0;
	while (cmd[i])
	{
		if (!(a = ft_strjoin_free1(a, cmd[i])))
			ERROR("ft_strjoin_free1 failed");
		if (!(a = ft_strjoin_free1(a, " ")))
			ERROR("ft_strjoin_free1 failed");
		++i;
	}
	return (a);
}

void		env_push_process(t_env *env, pid_t pid, char **cmd)
{
	t_process_list	*new;
	t_process_list	*lst;

	if (!(new = malloc(sizeof(*new))))
		ERROR("malloc failed");
	new->process.pid = pid;
	new->process.cmd = cmd_rebuild(cmd);
	new->next = NULL;
	if (!env->processes)
	{
		env->processes = new;
		return ;
	}
	lst = env->processes;
	while (lst->next)
		lst = lst->next;
	lst->next = new;
}
