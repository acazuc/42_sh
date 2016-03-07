/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_manager.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 15:13:04 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/07 10:30:19 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIR_MANAGER_H
# define REDIR_MANAGER_H

typedef struct	s_redir_manager
{
	int			old_fd[10];
	int			closed[10];
	int			has_changed[10];
}				t_redir_manager;

#endif
