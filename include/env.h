/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 08:34:57 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 14:57:23 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "alias_list.h"
# include "cmd_hist.h"

typedef struct		s_env
{
	t_alias_list	*aliases;
	t_cmd_hist		*cmd_hist;
	pid_t			child_pid;
	char			**ev;
	char			*cwd;
	int				pipe_1[2];
	int				pipe_2[2];
	int				which_pipe;
	int				hist_pos;
}					t_env;

#endif
