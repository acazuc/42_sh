/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_alias_list.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 17:38:30 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 23:11:31 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALIAS_LIST_H
# define ALIAS_LIST_H

# include "alias.h"

typedef struct s_alias_list	t_alias_list;

struct						s_alias_list
{
	t_alias					alias;
	t_alias_list			*next;
};

#endif
