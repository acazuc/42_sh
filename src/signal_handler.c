/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 17:23:35 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/26 15:58:15 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		handle_3(int signal)
{
	if (signal == SIGTTOU)
		ft_putstr_fd("background write attempted to control terminal", 2);
	else if (signal == SIGXCPU)
		ft_putstr_fd("cpu time limit exceeded", 2);
	else if (signal == SIGXFSZ)
		ft_putstr_fd("file size limit exceeded", 2);
	else if (signal == SIGVTALRM)
		ft_putstr_fd("virtual time alarm", 2);
	else if (signal == SIGPROF)
		ft_putstr_fd("profiling timer alarm", 2);
	else if (signal == SIGUSR1)
		ft_putstr_fd("user defined signal 1", 2);
	else if (signal == SIGUSR2)
		ft_putstr_fd("user defined signal 2", 2);
	else
		ft_putstr_fd("Unknown signal", 2);
}

static void		handle_2(int signal)
{
	if (signal == SIGFPE)
		ft_putstr_fd("floating-point exception", 1);
	else if (signal == SIGBUS)
		ft_putstr_fd("bus error", 2);
	else if (signal == SIGSEGV)
		ft_putstr_fd("segmentation fault", 2);
	else if (signal == SIGSYS)
		ft_putstr_fd("non-existent system call invoked", 2);
	else if (signal == SIGPIPE)
		ft_putstr_fd("write on a pipe with no reader", 2);
	else if (signal == SIGALRM)
		ft_putstr_fd("real-tine timer expired", 2);
	else if (signal == SIGTERM)
		ft_putstr_fd("software termination signal", 2);
	else if (signal == SIGSTOP)
		ft_putstr_fd("stop", 2);
	else if (signal == SIGTSTP)
		ft_putstr_fd("stop", 2);
	else if (signal == SIGTTIN)
		ft_putstr_fd("background read attempted from control terminal", 2);
	else
		handle_3(signal);
}

void			signal_handler(int status, char *cmd)
{
	int		signal;

	if (WIFSIGNALED(status))
	{
		ft_putstr_fd("cash: ", 2);
		signal = WTERMSIG(status);
		if (signal == SIGHUP)
			ft_putstr_fd("terminal line hangup", 2);
		else if (signal == SIGQUIT)
			ft_putstr_fd("quit program", 2);
		else if (signal == SIGILL)
			ft_putstr_fd("illegal instruction", 2);
		else if (signal == SIGTRAP)
			ft_putstr_fd("trace trap", 2);
		else if (signal == SIGABRT)
			ft_putstr_fd("abort program", 2);
		else
			handle_2(signal);
		ft_putchar_fd(' ', 2);
		ft_putendl_fd(cmd, 2);
	}
}
