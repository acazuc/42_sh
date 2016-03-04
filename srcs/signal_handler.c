/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 17:23:35 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/04 16:38:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		handle_3(int signal)
{
	if (signal == SIGTTOU)
		ft_putendl("background write attempted to control terminal");
	else if (signal == SIGXCPU)
		ft_putendl("cpu time limit exceeded");
	else if (signal == SIGXFSZ)
		ft_putendl("file size limit exceeded");
	else if (signal == SIGVTALRM)
		ft_putendl("virtual time alarm");
	else if (signal == SIGPROF)
		ft_putendl("profiling timer alarm");
	else if (signal == SIGUSR1)
		ft_putendl("user defined signal 1");
	else if (signal == SIGUSR2)
		ft_putendl("user defined signal 2");
	else
		ft_putendl("Unknown signal error");
}

static void		handle_2(int signal)
{
	if (signal == SIGFPE)
		ft_putendl("floating-point exception");
	else if (signal == SIGKILL)
		ft_putendl("kill program");
	else if (signal == SIGBUS)
		ft_putendl("bus error");
	else if (signal == SIGSEGV)
		ft_putendl("segmentation violation");
	else if (signal == SIGSYS)
		ft_putendl("non-existent system call invoked");
	else if (signal == SIGPIPE)
		ft_putendl("write on a pipe with no reader");
	else if (signal == SIGALRM)
		ft_putendl("real-tine timer expired");
	else if (signal == SIGTERM)
		ft_putendl("software termination signal");
	else if (signal == SIGSTOP)
		ft_putendl("stop");
	else if (signal == SIGTSTP)
		ft_putendl("stop");
	else if (signal == SIGTTIN)
		ft_putendl("background read attempted from control terminal");
	else
		handle_3(signal);
}

void			signal_handler(int status)
{
	int		signal;

	if (WIFSIGNALED(status))
	{
		signal = WTERMSIG(status);
		if (signal == SIGHUP)
			ft_putendl("terminal line hangup");
		else if (signal == SIGQUIT)
			ft_putendl("quit program");
		else if (signal == SIGILL)
			ft_putendl("illegal instruction");
		else if (signal == SIGTRAP)
			ft_putendl("trace trap");
		else if (signal == SIGABRT)
			ft_putendl("abort program");
		else if (signal == SIGEMT)
			ft_putendl("emulate instruction executed");
		else
			handle_2(signal);
	}
}
