/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_hist_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:32:41 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/24 15:40:45 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	cmd_hist_check(t_env *env)
{
	t_cmd_hist	*lst;
	t_cmd_hist	*prv;
	int			i;

	lst = env->cmd_hist;
	i = 0;
	while (lst)
	{
		if (i == 100)
		{
			free(lst->cmd);
			free(lst);
			prv->next = NULL;
		}
		prv = lst;
		lst = lst->next;
		i++;
	}
}
