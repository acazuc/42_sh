/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 16:20:01 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/26 17:36:32 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

void	error_quit(char *message, char *file, int line);
void	signal_handler(int status, char *cmd);
int		builtins(t_env *env, char **datas);
int		builtin_cd(t_env *env, char **datas, int len);
int		builtin_echo(t_env *env, char **datas, int len);
int		builtin_alias(t_env *env, char **datas, int len);
int		builtin_about(t_env *env, char **datas, int len);
int		builtin_setenv(t_env *env, char **datas, int len);
int		builtin_getenv(t_env *env, char **datas, int len);
int		builtin_unsetenv(t_env *env, char **datas, int len);
int		builtin_unalias(t_env *env, char **datas, int len);
int		builtin_env(t_env *env, char **datas, int len);
int		builtin_source(t_env *env, char **datas, int len);
int		builtin_export(t_env *env, char **datas, int len);
int		builtin_exit(t_env *env, char **datas, int len);
void	print_line(t_env *env);
char	*get_username(t_env *env);
char	*get_working_directory(void);
char	*get_home_with_tilde(t_env *env, char *cwd);
void	sigint_handler(int signal);
void	command_run(t_env *env, char **args);
char	*get_home_directory(t_env *env);
char	*get_path(t_env *env);
void	env_value_set(t_env *env, char *key, char *value);
void	env_value_remove(t_env *env, char *key);
int		env_value_exists(t_env *env, char *key);
char	*env_value_get(t_env *env, char *key);
char	*replace_tilde_home(t_env *env, char *str);
char	*get_host_name(void);
void	exec_command(t_env *env, char **args);
void	command_run_piped(t_env *env, char **arg, int pipe);
void	parse_command_push_param(t_parser *p);
void	parse_command_unquote(char **cmd);
void	parse_command_quotes(t_parser *parser, int i);
void	parse_command_backslashs(char **cmd);
void	parse_command_vars(t_env *env, char **cmd);
void	parse_command_tilde(t_env *env, char **cmd);
void	parse_command_empty(char ***cmd);
char	*parse_command_short(char *cmd);
void	parse_command_quotes(t_parser *parser, int i);
char	**parse_command_split(char *cmd);
char	*parse_command_unescape(char *var);
void	parse_command_split_push_redir(t_parser *p);
char	*read_next_line(int fd, ssize_t *readed);
char	*get_next_cmd(void);
char	get_next_cmd_missing(char *str);
void	cmd_hist_add(t_env *env, char *cmd);
void	cmd_hist_check(t_env *env);
void	alias_create(t_env *env, char *alias, char *cmd);
int		alias_remove(t_env *env, char *alias);
void	alias_free(t_alias_list *alias);
int		alias_exists(t_env *env, char *alias);
void	alias_set(t_env *env, char *alias, char *cmd);
void	alias_clean_passed(t_env *env);
void	command_split_push(char ***sub, char *add);
void	command_split_clear(char ***sub);
void	command_split_semicolon(t_env *env, char **cmd);
void	command_split_pipe(t_env *env, char **cmd);
int		command_split_redirs(t_env *env, char **cmd);
int		command_split_redirs_in(t_redir_manager *m, char **cmd, size_t *i);
int		command_split_redirs_out(t_redir_manager *m, char **cmd, size_t *i);
int		get_bs_nb_before(char *str, size_t i);
int		command_check_pipes(char **args);
int		command_check_redirs(char **args);
int		redir_add(t_redir_manager *m, int fd_in, int fd_out, int from_file);
int		redir_close(t_redir_manager *m, int fd);
int		redir_in_add_file(t_redir_manager *m, int fd, char *file);
int		redir_out_add_file(t_redir_manager *m, int fd, int append, char *file);
void	redir_reset(t_redir_manager *m);
void	command_execute(t_env *env, char *line);
void	processes_wait(t_env *env);
void	env_push_process(t_env *env, pid_t pid, char **cmd);
void	command_replace_alias(t_env *env, char ***cmd);

#endif
