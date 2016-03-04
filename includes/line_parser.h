/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parser.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 13:39:44 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/04 13:50:11 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_PARSER_H
# define LINE_PARSER_H

typedef struct		s_line_parser
{
	int				dquote;
	int				squote;
	int				bquote;
	int				subsh;
	int				bracket;
	int				cursh;
}					t_line_parser;

#endif
