/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 16:20:01 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/23 11:44:39 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "parser.h"
# include "env.h"

void	error_quit(char *message);
void	signal_handler(int status);
void	parse_line(t_env *env, char *cmd);
char	**parse_command_params(char *cmd);
char	**parse_command_semicolon(char *cmd);
void	parse_command_add_param(char ***tab, char *str);
int		builtins(t_env *env, char **datas, int len);
int		builtin_cd(t_env *env, char **datas, int len);
int		builtin_exit(char **datas, int len);
int		builtin_setenv(t_env *env, char **datas, int len);
int		builtin_getenv(t_env *env, char **datas, int len);
int		builtin_unsetenv(t_env *env, char **datas, int len);
int		builtin_env(t_env *env, char **datas, int len);
void	print_line(t_env *env);
char	*get_username(t_env *env);
char	*get_working_directory(void);
void	sigint_handler(int signal);
void	command_run(t_env *env, char **args);
char	*get_home_directory(t_env *env);
char	*get_path(t_env *env);
char	*get_env_value(t_env *env, char *key);
char	*replace_tilde_home(t_env *env, char *str);
char	*get_host_name(void);
void	command_run_redirs(t_env *env, char *cmd);
void	exec_command(t_env *env, char **args);
void	parse_command_quotes(t_parser *parser, int i);
void	parse_command_init(t_parser *parser, char *cmd);
void	parse_command_reset(t_parser *parser);
void	command_run_piped(t_env *env, char **arg, int pipe);

#endif
