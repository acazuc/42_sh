/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 13:26:34 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/26 19:01:32 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# define PIPE_NO 0
# define PIPE_I 1
# define PIPE_O 2
# define PIPE_IO 3

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

# include "../libft/include/libft.h"
# include "structs.h"
# include "prototypes.h"

# define ERROR(x) (error_quit(x, __FILE__, __LINE__))

#endif
