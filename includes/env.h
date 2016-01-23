/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 08:34:57 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/23 11:09:07 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef struct		s_env
{
	pid_t			child_pid;
	char			**ev;
	int				pipe_1[2];
	int				pipe_2[2];
	int				which_pipe;
}					t_env;

#endif
