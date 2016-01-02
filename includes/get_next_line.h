/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 09:06:54 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/02 16:47:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1

int					get_next_line(const int fd, char **line);

typedef struct		s_env
{
	char			**line;
	char			**start;
	char			**buffer;
	int				fd;
}					t_env;

#endif
