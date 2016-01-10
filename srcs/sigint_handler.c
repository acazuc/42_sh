/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:39:24 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/10 16:48:41 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	sigint_handler(int signal)
{
	//Do nothing in fact, just silent the signal and put new line
	ft_putchar('\n');
	print_line();
	(void)signal;
}
