/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 11:28:58 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/15 12:09:41 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

void	run_redir(char *args[3], char *file, int append)
{
	pid_t	pid;
	int		fd;
	int		old;
	int		flags;

	old = dup(1);
	pid = fork();
	if (pid == -1)
	{
		perror("test2");
		exit(-1);
	}
	else if (pid == 0)
	{
		flags = O_WRONLY | O_CREAT;
		if (append)
			flags |= O_APPEND;
		else
			flags |= O_TRUNC;
		if ((fd = open(file, flags, 0666)) == -1)
		{
			perror("test3");
			exit(-1);
		}
		dup2(fd, 1);
		execve(args[0], args, NULL);
		perror("test3");
	}
	wait(NULL);
	close(1);
	dup2(old, 1);
	close(old);
}

void	set_params(char ***args, char *cmd_val, char *arg_val)
{
	if (!(*args = malloc(sizeof(**args) * 3)))
	{
		perror("test1");
		exit(-1);
	}
	(*args)[0] = ft_strdup(cmd_val);
	(*args)[1] = ft_strdup(arg_val);
	(*args)[2] = NULL;
}

int		main(void)
{
	char	**args;
	
	set_params(&args, "/bin/ls", "-l");
	run_redir(args, "simple_redir", 0);
}
