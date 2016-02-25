/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 12:48:58 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/25 12:53:52 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_BS_H
# define PARSER_BS_H

typedef struct	s_parser_sb
{
	size_t		i;
	int			c;
	int			in_squote;
	int			in_dquote;
}				t_parser_bs;

#endif
