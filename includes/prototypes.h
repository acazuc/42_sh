/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 16:20:01 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/10 16:33:46 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "command.h"

void	error_quit(char *message);
void	signal_handler(int status);
int		parse_command(t_command *command, char *command_line);
int		changedir(char *dir);
int		builtins(char **datas, int len);
int		builtin_cd(char **datas, int len);
int		builtin_exit(char **datas, int len);
void	print_line(void);
char	*get_username();
char	*get_working_directory();

#endif
