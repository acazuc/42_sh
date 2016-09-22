/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 13:58:22 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/22 15:59:23 by acazuc           ###   ########.fr       */
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

static char		*do_return(ssize_t rd, char *line)
{
	if (rd == -1)
	{
		free(line);
		return (NULL);
	}
	else if (rd == 0 && !(line = ft_strjoin_free1(line, "\n")))
		return (NULL);
	return (line);
}

char			*read_next_line(int fd, ssize_t *readed)
{
	char	*line;
	char	*buff;
	ssize_t	rd;

	*readed = 0;
	if (!init(&line, &buff))
		return (NULL);
	while ((rd = read(fd, buff, 1)) > 0 && buff[0] != '\n')
	{
		*readed += rd;
		if (!(line = ft_strjoin_free1(line, buff)))
		{
			free(buff);
			return (NULL);
		}
	}
	*readed += rd;
	free(buff);
	return (do_return(rd, line));
}
