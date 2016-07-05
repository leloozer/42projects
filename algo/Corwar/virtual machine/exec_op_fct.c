/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op_fct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:28:25 by rmorel            #+#    #+#             */
/*   Updated: 2016/03/29 21:03:12 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

size_t	mod_mem(size_t n)
{
	return (n % MEM_SIZE);
}

size_t	mod_idx(size_t n, t_process *p, size_t s)
{
	size_t	add;

	add = n % IDX_MOD;
	if ((s == 2 && n < 32768) || (s == 4 && n < 2147483648))
		return (mod_mem(add + p->pc));
	add = IDX_MOD - add;
	if (add <= p->pc)
		return (p->pc - add);
	else
		return ((MEM_SIZE + p->pc) - add);
}

int		is_reg(size_t reg)
{
	return (reg >= 1 && reg <= REG_NUMBER);
}

void	r_copy(unsigned char *src, unsigned char *dst, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
}

size_t	mod_idx2(unsigned int a2, unsigned int a3, t_process *p)
{
	if (mod_mem(a2 + a3) < 2048)
		return (mod_idx(a2 + a3, p, 4));
	else
		return (mod_mem(a2 + a3) + p->pc);
}
