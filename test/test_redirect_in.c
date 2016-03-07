/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_redirect_in.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 12:03:09 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/07 09:23:35 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

void	run_redir(char *args[3], char *file)
{
	pid_t	pid;
	int		fd;
	int		old;

	old = dup(0);
	pid = fork();
	if (pid == -1)
	{
		perror("test1");
		exit(-1);
	}
	else if (pid == 0)
	{
		if ((fd = open(file, O_RDONLY)) == -1)
		{
			perror("test2");
			exit(-1);
		}
		dup2(fd, 0);
		execve(args[0], args, NULL);
		perror("test3");
	}
	wait(NULL);
	close(0);
	dup2(old, 0);
	close(old);
}

void	set_params(char ***args, char *cmd_val, char *arg_val)
{
	if (!(*args = malloc(sizeof(**args) * 3)))
	{
		perror("test4");
		exit(-1);
	}
	(*args)[0] = ft_strdup(cmd_val);
	(*args)[1] = ft_strdup(arg_val);
	(*args)[2] = NULL;
}

int		main(void)
{
	char	**args;

	set_params(&args, "/bin/cat", "-e");
	run_redir(args, "simple_redir");
}
