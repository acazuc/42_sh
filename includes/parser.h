/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 18:37:20 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/24 13:50:58 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct		s_parser
{
	char			**result;
	char			*cmd;
	int				in_dquote;
	int				in_squote;
	int				start;
	int				i;
}					t_parser;

#endif
