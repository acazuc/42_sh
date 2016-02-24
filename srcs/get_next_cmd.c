/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 13:58:22 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/24 14:25:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*get_next_cmd(void)
{
	char	*line;
	char	*buff;
	int		rd;

	if (!(line = malloc(sizeof(*line))))
		return (NULL);
	line[0] = '\0';
	if (!(buff = malloc(sizeof(*buff) * 2)))
	{
		free(line);
		return (NULL);
	}
	buff[0] = '\0';
	buff[1] = '\0';
	while ((rd = read(1, buff, 1)) > 0 && buff[0] != '\n')
	{
		if (!(line = ft_strjoin_free1(line, buff)))
		{
			free(buff);
			return (NULL);
		}
	}
	free(buff);
	if (rd == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
