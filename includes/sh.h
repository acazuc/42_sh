/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 13:26:34 by acazuc            #+#    #+#             */
/*   Updated: 2016/03/06 16:56:00 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# define PIPE_NO 0
# define PIPE_I 1
# define PIPE_O 2
# define PIPE_IO 3

# include "../libft/includes/libft.h"
# include "cmd_hist.h"
# include "redir_manager.h"
# include "pipe_manager.h"
# include "parser_bs.h"
# include "line_parser.h"
# include "prototypes.h"
# include "includes.h"
# include "parser.h"
# include "env.h"

# define ERROR(x) (error_quit(x, __FILE__, __LINE__))

#endif
