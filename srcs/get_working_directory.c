/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_working_directory.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:28:22 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/11 10:22:53 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*get_working_directory()
{
	char	*wd;

	wd = getcwd(NULL, 0);
	return (wd);
}
