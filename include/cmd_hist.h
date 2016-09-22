/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_hist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:24:20 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/24 15:25:49 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_HIST_H
# define CMD_HIST_H

typedef struct s_cmd_hist	t_cmd_hist;

struct			s_cmd_hist
{
	char		*cmd;
	t_cmd_hist	*next;
};

#endif
