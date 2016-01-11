/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 14:58:22 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/11 09:54:06 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

typedef struct		s_command
{
	char			*command;
	char			**params;
}					t_command;

#endif
