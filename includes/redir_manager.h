/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_manager.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 15:13:04 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/06 16:40:18 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIR_MANAGER_H
# define REDIR_MANAGER_H

typedef struct	s_redir_manager
{
	int			closed[10];
	int			do_redir[10];
	int			to_redir[10];
	int			is_append[10];
}				t_redir_manager;

#endif
