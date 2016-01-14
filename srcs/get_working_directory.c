/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_working_directory.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:28:22 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/14 08:19:02 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*get_working_directory()
{
	char	*wd;

	if (!(wd = getcwd(NULL, 0)))
		error_quit("Failed to malloc working dir");
	return (wd);
}
