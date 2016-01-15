/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 08:03:47 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/15 11:39:52 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PIPE_IN 1
#define PIPE_OUT 2
#define PIPE_IN_OUT 3

void	run_pipe(char *args[3], int pipe_type, int *pipe_in, int *pipe_out)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("test1");
		exit(-1);
	}
	else if (pid == 0)
	{
		if (pipe_type & PIPE_OUT)
			dup2(pipe_out[1], 1);
		if (pipe_type & PIPE_IN)
			dup2(pipe_in[0], 0);
		execve(args[0], args, NULL);
		perror("test2");
	}
	wait(NULL);
	if (pipe_type & PIPE_OUT)
		close(pipe_out[1]);
	if (pipe_type & PIPE_IN)
		close(pipe_in[0]);
}

void	set_params(char ***args, char *cmd_val, char *arg_val)
{
	if (!(*args = malloc(sizeof(**args) * 3)))
	{
		perror("test3");
		exit(-1);
	}
	(*args)[0] = ft_strdup(cmd_val);
	(*args)[1] = ft_strdup(arg_val);
	(*args)[2] = NULL;
}

void	init_pipe(int **p)
{
	if (!(*p = malloc(sizeof(*p) * 2)))
	{
		perror("test4");
		exit(-1);
	}
	if (pipe(*p) == -1)
	{
		perror("test5");
		exit(-1);
	}
}

void	re_init_pipe(int **p)
{
	free(*p);
	init_pipe(p);
}

int		main(void)
{
	char	**args;
	int		*pipe_1;
	int		*pipe_2;

	init_pipe(&pipe_1);
	init_pipe(&pipe_2);
	set_params(&args, "/bin/ls", "-l");
	run_pipe(args, PIPE_OUT, pipe_1, pipe_2);
	set_params(&args, "/bin/cat", "-e");
	run_pipe(args, PIPE_IN_OUT, pipe_2, pipe_1);
	re_init_pipe(&pipe_2);
	set_params(&args, "/bin/cat", "-e");
	run_pipe(args, PIPE_IN_OUT, pipe_1, pipe_2);
	re_init_pipe(&pipe_1);
	set_params(&args, "/bin/cat", "-e");
	run_pipe(args, PIPE_IN_OUT, pipe_2, pipe_1);
	re_init_pipe(&pipe_2);
	set_params(&args, "/bin/cat", "-e");
	run_pipe(args, PIPE_IN, pipe_1, pipe_2);
	close(pipe_1[0]);
	close(pipe_1[1]);
	close(pipe_2[0]);
	close(pipe_2[1]);
	return (0);
}
