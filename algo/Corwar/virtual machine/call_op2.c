/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_op2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:28:18 by rmorel            #+#    #+#             */
/*   Updated: 2016/03/29 21:04:02 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned char	proper_size(unsigned char a, size_t op)
{
	if (a == 4 && op >= 9 && op <= 15 && op != 13)
		return (2);
	return (a);
}

unsigned char	get_offset(unsigned char size[3])
{
	unsigned char	val;

	val = 0;
	val += size[0];
	val += size[1];
	val += size[2];
	return (val);
}

int				valid_op(unsigned char op)
{
	return (op > 0 && op < 20);
}

size_t			arg_size(unsigned char type)
{
	if (type == 1)
		return (1);
	if (type == 3)
		return (2);
	if (type == 2)
		return (4);
	return (0);
}
