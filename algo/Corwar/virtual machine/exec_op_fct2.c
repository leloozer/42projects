/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op_fct2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:28:25 by rmorel            #+#    #+#             */
/*   Updated: 2016/03/29 21:03:12 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	reg_copy(unsigned char *src, unsigned char *reg, size_t size)
{
	size_t	i;

	i = 0;
	while (i < REG_SIZE)
		reg[i++] = 0;
	i = 0;
	while (i < size)
	{
		reg[i + (REG_SIZE - size)] = src[i];
		i++;
	}
}

size_t	r_to_n(unsigned char *tab, size_t size)
{
	unsigned char	u[8];
	size_t			i;

	i = 0;
	while (i < 8)
		u[i++] = 0;
	i = 0;
	while (size - i > 0 && i < 8)
	{
		u[i] = tab[size - i - 1];
		i++;
	}
	return (*((size_t *)u));
}

size_t	mem_to_n(unsigned char *mem, size_t start, size_t size)
{
	unsigned char	u[8];
	size_t			i;

	i = 0;
	while (i < 8)
		u[i++] = 0;
	i = 0;
	while (size > i && i < 8)
	{
		u[i] = mem[mod_mem(start + size - (i + 1))];
		i++;
	}
	return (*((size_t *)u));
}

void	n_to_mem(t_env *env, t_process *p, size_t start, size_t n)
{
	size_t			i;
	unsigned char	*u;

	i = 0;
	u = (unsigned char *)&n;
	while (i < REG_SIZE)
	{
		env->mem[mod_mem(start + REG_SIZE - (i + 1))] = u[i];
		env->color[mod_mem(start + REG_SIZE - (i + 1))] = p->reg[0][3];
		i++;
	}
}

void	n_to_r(unsigned char *tab, size_t size, size_t n)
{
	size_t			i;
	unsigned char	*u;

	i = 0;
	u = (unsigned char *)&n;
	while (i < size)
	{
		tab[size - (i + 1)] = u[i];
		i++;
	}
}
