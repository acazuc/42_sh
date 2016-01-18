/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_working_directory.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:28:22 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/18 10:46:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*get_working_directory(void)
{
	char	*wd;

	if (!(wd = getcwd(NULL, 0)))
		error_quit("Failed to malloc working dir");
	return (wd);
}
