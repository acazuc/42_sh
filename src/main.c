/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 13:22:58 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/26 18:20:07 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_env	*g_env;

static char	**dup_ev(char **ev)
{
	char	**new;
	int		len;

	len = 0;
	while (ev[len])
		len++;
	if (!(new = malloc(sizeof(*new) * (len + 1))))
		ERROR("Failed to malloc new env");
	len = 0;
	while (ev[len])
	{
		new[len] = ft_strdup(ev[len]);
		len++;
	}
	new[len] = NULL;
	return (new);
}

static void	loop(t_env *env)
{
	char	*line;

	print_line(env);
	if ((line = get_next_cmd()))
	{
		command_execute(env, line);
		free(line);
	}
}

static void	check_cashrc(t_env *env)
{
	struct stat	sstat;
	char		*str;

	if (!(str = get_home_directory(env)))
		return ;
	if (!(str = ft_strjoin_free1(str, "/.cashrc")))
	{
		free(str);
		return ;
	}
	if (stat(str, &sstat) == -1 || !S_ISREG(sstat.st_mode))
	{
		free(str);
		return ;
	}
	free(str);
	command_execute(env, "source ~/.cashrc");
}

int			main(int ac, char **av, char **ev)
{
	t_env		env;

	ft_bzero(&env, sizeof(env));
	g_env = &env;
	env.ev = dup_ev(ev);
	if (pipe(env.pipe_1) == -1)
		ERROR("Failed to pipe");
	if (pipe(env.pipe_2) == -1)
		ERROR("Failed to pipe");
	signal(SIGINT, &sigint_handler);
	if (!(env.cwd = get_working_directory()))
		ERROR("Failed to get current working directory");
	if (!(env.cwd = get_home_with_tilde(&env, env.cwd)))
		ERROR("Failed to get current working directory with tilde");
	check_cashrc(&env);
	while (42)
		loop(&env);
	(void)ac;
	(void)av;
	return (0);
}
