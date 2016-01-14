/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 17:02:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/14 17:21:01 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


void	run_pipe()
{
	pid_t	child;
	char	*cmd1;
	char	*cmd2;
	char	*args1[3];
	char	*args2[3];
	int		pdes[2];

	cmd1 = "/bin/ls";
	args1[0] = cmd1;
	args1[1] = "-lF";
	args1[2] = NULL;

	cmd2 = "/bin/cat";
	args2[0] = cmd2;
	args2[1] = "-e";
	args2[2] = NULL;

	pipe(pdes);
	child = fork();
	if (child == -1)
	{
		close(pdes[0]);
		close(pdes[1]);
		perror("test3");
	}
	else if (child == 0)
	{
		dup2(pdes[1], 1);
		close(pdes[0]);
		execve(cmd1, args1, NULL);
		perror("test4");
	}
	else
	{
		dup2(pdes[0], 0);
		close(pdes[1]);
		wait(NULL);
		execve(cmd2, args2, NULL);
		perror("test5");
	}
}

int		main(void)
{
	pid_t	child;

	child = fork();
	if (child == -1)
	{
		perror("test");
		return (-1);
	}
	else if (child == 0)
	{
		run_pipe();
		perror("test2");
		return (-1);
	}
	else
	{
		wait(NULL);
	}
	return (0);
}
