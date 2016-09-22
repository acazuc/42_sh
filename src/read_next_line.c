/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 13:58:22 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 15:15:41 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int		init(char **line, char **buff)
{
	if (!(*line = malloc(sizeof(**line))))
		return (0);
	(*line)[0] = '\0';
	if (!(*buff = malloc(sizeof(**buff) * 2)))
	{
		free(*line);
		return (0);
	}
	(*buff)[0] = '\0';
	(*buff)[1] = '\0';
	return (1);
}

char			*read_next_line(int fd)
{
	char	*line;
	char	*buff;
	int		rd;

	if (!init(&line, &buff))
		return (NULL);
	while ((rd = read(fd, buff, 1)) > 0 && buff[0] != '\n')
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
	else if (rd == 0 && !(line = ft_strjoin_free1(line, "\n")))
		return (NULL);
	return (line);
}
