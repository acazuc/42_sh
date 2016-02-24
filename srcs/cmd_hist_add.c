/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_hist_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:28:50 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/24 15:41:01 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	cmd_hist_add(t_env *env, char *cmd)
{
	t_cmd_hist	*new;

	if (!(new = malloc(sizeof(*new))))
		error_quit("Failed to malloc new cmd hist");
	new->cmd = cmd;
	new->next = env->cmd_hist;
	cmd_hist_check(env);
}
