/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_wait.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 15:32:56 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/26 15:54:34 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	processes_wait(t_env *env)
{
	t_process_list	*lst;
	int				status;

	while (env->processes)
	{
		waitpid(env->processes->process.pid, &status, 0);
		signal_handler(status, env->processes->process.cmd);
		free(env->processes->process.cmd);
		lst = env->processes;
		env->processes = lst->next;
		free(lst);
	}
}
