# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 06:50:12 by acazuc            #+#    #+#              #
#    Updated: 2016/08/03 21:44:53 by acazuc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cash

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Ofast

INCLUDES_PATH = includes/

SRCS_PATH = srcs/

SRCS_NAME = main.c \
			error_quit.c \
			signal_handler.c \
			builtins.c \
			builtin_cd.c \
			builtin_echo.c \
			builtin_about.c \
			builtin_alias.c \
			builtin_getenv.c \
			builtin_setenv.c \
			builtin_unsetenv.c \
			builtin_env.c \
			print_line.c \
			get_working_directory.c \
			get_username.c \
			sigint_handler.c \
			command_run.c \
			get_home_directory.c \
			get_path.c \
			get_env_value.c \
			get_host_name.c \
			command_run_piped.c \
			set_env_value.c \
			get_next_cmd.c \
			get_next_cmd_missing.c \
			read_next_line.c \
			cmd_hist_check.c \
			cmd_hist_add.c \
			alias_create.c \
			alias_remove.c \
			alias_free.c \
			command_split_push.c \
			command_split_clear.c \
			command_split_semicolon.c \
			command_split_pipe.c \
			command_split_redirs.c \
			parse_command_split.c \
			parse_command_split_push_redir.c \
			parse_command_push_param.c \
			parse_command_tilde.c \
			parse_command_vars.c \
			parse_command_empty.c \
			parse_command_unescape.c \
			parse_command_short.c \
			parse_command_backslashs.c \
			parse_command_unquote.c \
			get_bs_nb_before.c \
			command_check_pipes.c \
			command_check_redirs.c \
			redirs_functions.c \

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = objs/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIBRARY = -L libft/ -lft

all: odir $(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	@echo " - Making $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBRARY)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo " - Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_PATH)

odir:
	@mkdir -p $(OBJS_PATH)

clean:
	@make -C libft/ clean
	@echo " - Cleaning objs"
	@rm -f $(OBJS)

fclean: clean
	@make -C libft/ fclean
	@echo " - Cleaning executable"
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re odir
