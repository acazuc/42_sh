/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 16:20:01 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/10 15:25:28 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "command.h"

void	error_quit(char *message);
void	signal_handler(int status);
int		parse_command(t_command *command, char *command_line);
int		changedir(char *dir);

#endif
