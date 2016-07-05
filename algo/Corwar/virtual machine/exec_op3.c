/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:28:25 by rmorel            #+#    #+#             */
/*   Updated: 2016/03/29 21:03:12 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_or(t_env *env, t_process *p, unsigned char arg[4][4], size_t *t)
{
	unsigned int	a1;
	unsigned int	a2;
	size_t			a3;

	p->carry = 0;
	a1 = r_to_n(arg[0], t[0]);
	a2 = r_to_n(arg[1], t[1]);
	a3 = r_to_n(arg[2], 1);
	if ((t[0] == 1 && !is_reg(a1)) || (t[1] == 1 && !is_reg(a2)) || !is_reg(a3))
		return ;
	if (t[0] == 1)
		a1 = r_to_n(p->reg[a1 - 1], REG_SIZE);
	if (t[1] == 1)
		a2 = r_to_n(p->reg[a2 - 1], REG_SIZE);
	if (t[0] == 2)
		a1 = mem_to_n(env->mem, mod_idx(a1, p, 2), 4);
	if (t[1] == 2)
		a2 = mem_to_n(env->mem, mod_idx(a2, p, 2), 4);
	n_to_r(p->reg[a3 - 1], 4, a1 | a2);
	if (!(a1 | a2))
		p->carry = 1;
}

void	op_xor(t_env *env, t_process *p, unsigned char arg[4][4], size_t *t)
{
	unsigned int	a1;
	unsigned int	a2;
	size_t			a3;

	p->carry = 0;
	a1 = r_to_n(arg[0], t[0]);
	a2 = r_to_n(arg[1], t[1]);
	a3 = r_to_n(arg[2], 1);
	if ((t[0] == 1 && !is_reg(a1)) || (t[1] == 1 && !is_reg(a2)) || !is_reg(a3))
		return ;
	if (t[0] == 1)
		a1 = r_to_n(p->reg[a1 - 1], REG_SIZE);
	if (t[1] == 1)
		a2 = r_to_n(p->reg[a2 - 1], REG_SIZE);
	if (t[0] == 2)
		a1 = mem_to_n(env->mem, mod_idx(a1, p, 2), 4);
	if (t[1] == 2)
		a2 = mem_to_n(env->mem, mod_idx(a2, p, 2), 4);
	n_to_r(p->reg[a3 - 1], 4, a1 ^ a2);
	if (!(a1 ^ a2))
		p->carry = 1;
}

void	op_zjmp(t_env *env, t_process *p, unsigned char arg[4][4], size_t *t)
{
	size_t	a1;

	(void)env;
	(void)t;
	a1 = r_to_n(arg[0], 2);
	if (!p->carry)
	{
		p->pc += 3;
		return ;
	}
	p->pc = mod_idx(a1, p, 2);
}

void	op_ldi(t_env *env, t_process *p, unsigned char arg[4][4], size_t *t)
{
	size_t	a1;
	size_t	a2;
	size_t	a3;
	size_t	val;

	if (t[0] == 1)
		a1 = r_to_n(arg[0], 1);
	else
		a1 = r_to_n(arg[0], 2);
	if (t[1] == 1)
		a2 = r_to_n(arg[1], 1);
	else
		a2 = r_to_n(arg[1], 2);
	a3 = r_to_n(arg[2], 1);
	if ((t[0] == 1 && !is_reg(a1)) || (t[1] == 1 && !is_reg(a2)) || !is_reg(a3))
		return ;
	if (t[0] == 1)
		a1 = r_to_n(p->reg[a1 - 1], REG_SIZE);
	else if (t[0] == 2)
	{
		a1 = mem_to_n(env->mem, mod_idx(a1, p, 2), 4);
	}
	if (t[1] == 1)
		a2 = r_to_n(p->reg[a2 - 1], REG_SIZE);
	val = mem_to_n(env->mem, mod_idx2(a1, a2, p), REG_SIZE);
	n_to_r(p->reg[a3 - 1], REG_SIZE, val);
}

void	op_sti(t_env *env, t_process *p, unsigned char arg[4][4], size_t *t)
{
	size_t			a1;
	unsigned int	a2;
	unsigned int	a3;
	size_t			val;

	a1 = r_to_n(arg[0], 1);
	if (t[1] == 1)
		a2 = r_to_n(arg[1], 1);
	else
		a2 = r_to_n(arg[1], 2);
	if (t[2] == 1)
		a3 = r_to_n(arg[2], 1);
	else
		a3 = r_to_n(arg[2], 2);
	if (!is_reg(a1) || (t[1] == 1 && !is_reg(a2)) || (t[2] == 1 && !is_reg(a3)))
		return ;
	a1 = r_to_n(p->reg[a1 - 1], REG_SIZE);
	if (t[1] == 1)
		a2 = r_to_n(p->reg[a2 - 1], REG_SIZE);
	else if (t[1] == 2)
		a2 = mem_to_n(env->mem, mod_idx(a2, p, 2), 4);
	if (t[2] == 1)
		a3 = r_to_n(p->reg[a3 - 1], REG_SIZE);
	val = mod_idx2(a2, a3, p);
	n_to_mem(env, p, val, a1);
}
