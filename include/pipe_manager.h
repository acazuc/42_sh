/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_manager.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 09:48:02 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/06 09:59:24 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_MANAGER_H
# define PIPE_MANAGER_H

typedef struct		s_pipe_manager
{
	int				origin_stdin;
	int				origin_stdout;
	int				*pipe_in;
	int				*pipe_out;
	int				pipe_type;
}					t_pipe_manager;

#endif
