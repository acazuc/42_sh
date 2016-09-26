/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 15:28:55 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/26 18:34:59 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_env			t_env;
typedef struct s_alias_list		t_alias_list;
typedef struct s_cmd_hist		t_cmd_hist;
typedef struct s_parser			t_parser;
typedef struct s_line_parser	t_line_parser;
typedef struct s_parser_bs		t_parser_bs;
typedef struct s_pipe_manager	t_pipe_manager;
typedef struct s_redir_manager	t_redir_manager;
typedef struct s_alias			t_alias;
typedef struct s_process		t_process;
typedef struct s_process_list	t_process_list;

struct							s_process
{
	pid_t						pid;
	char						*cmd;
};

struct							s_process_list
{
	t_process					process;
	t_process_list				*next;
};

struct							s_env
{
	t_process_list				*processes;
	t_alias_list				*aliases;
	t_cmd_hist					*cmd_hist;
	char						**ev;
	char						*cwd;
	int							pipe_1[2];
	int							pipe_2[2];
	int							which_pipe;
	int							hist_pos;
	int							sigint;
};

struct							s_alias
{
	char						*alias;
	char						**cmd;
	int							passed;
};

struct							s_alias_list
{
	t_alias						alias;
	t_alias_list				*next;
};

struct							s_cmd_hist
{
	char						*cmd;
	t_cmd_hist					*next;
};

struct							s_parser
{
	char						**result;
	char						*cmd;
	int							in_dquote;
	int							in_squote;
	int							start;
	int							i;
};

struct							s_line_parser
{
	char						*result;
	int							dquote;
	int							squote;
};

struct							s_parser_bs
{
	size_t						i;
	int							c;
	int							in_squote;
	int							in_dquote;
};

struct							s_pipe_manager
{
	int							origin_stdin;
	int							origin_stdout;
	int							*pipe_in;
	int							*pipe_out;
	int							pipe_type;
};

struct							s_redir_manager
{
	int							old_fd[10];
	int							closed[10];
	int							has_changed[10];
};

#endif
