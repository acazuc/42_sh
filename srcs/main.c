/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 13:22:58 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/24 11:29:06 by acazuc           ###   ########.fr       */
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
		error_quit("Failed to malloc new env");
	len = 0;
	while (ev[len])
	{
		new[len] = ft_strdup(ev[len]);
		len++;
	}
	new[len] = NULL;
	return (new);
}

int			main(int ac, char **av, char **ev)
{
	t_env		env;
	char		*line;

	g_env = &env;
	env.ev = dup_ev(ev);
	env.child_pid = 0;
	pipe(env.pipe_1);
	pipe(env.pipe_2);
	signal(SIGINT, &sigint_handler);
	while (42)
	{
		print_line(&env);
		get_next_line(1, &line);
		parse_line(&env, line);
	}
	(void)ac;
	(void)av;
	return (0);
}
