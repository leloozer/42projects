/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:28:25 by rmorel            #+#    #+#             */
/*   Updated: 2016/03/29 21:03:12 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_sub(t_env *env, t_process *p, unsigned char arg[4][4], size_t *t)
{
	unsigned int	a1;
	unsigned int	a2;
	size_t			a3;

	(void)env;
	(void)t;
	p->carry = 0;
	a1 = r_to_n(arg[0], 1);
	a2 = r_to_n(arg[1], 1);
	a3 = r_to_n(arg[2], 1);
	if (!is_reg(a1) || !is_reg(a2) || !is_reg(a3))
		return ;
	a1 = r_to_n(p->reg[a1 - 1], REG_SIZE);
	a2 = r_to_n(p->reg[a2 - 1], REG_SIZE);
	n_to_r(p->reg[a3 - 1], 4, a1 - a2);
	p->carry = 1;
}

void	op_mul(t_env *env, t_process *p, unsigned char arg[4][4], size_t *t)
{
	unsigned int	a1;
	unsigned int	a2;
	size_t			a3;

	(void)env;
	(void)t;
	p->carry = 0;
	a1 = r_to_n(arg[0], 1);
	a2 = r_to_n(arg[1], 1);
	a3 = r_to_n(arg[2], 1);
	if (!is_reg(a1) || !is_reg(a2) || !is_reg(a3))
		return ;
	a1 = r_to_n(p->reg[a1 - 1], REG_SIZE);
	a2 = r_to_n(p->reg[a2 - 1], REG_SIZE);
	n_to_r(p->reg[a3 - 1], 4, a1 * a2);
	p->carry = 1;
}

void	op_div(t_env *env, t_process *p, unsigned char arg[4][4], size_t *t)
{
	unsigned int	a1;
	unsigned int	a2;
	size_t			a3;

	(void)env;
	(void)t;
	p->carry = 0;
	a1 = r_to_n(arg[0], 1);
	a2 = r_to_n(arg[1], 1);
	a3 = r_to_n(arg[2], 1);
	if (!is_reg(a1) || !is_reg(a2) || !is_reg(a3))
		return ;
	a1 = r_to_n(p->reg[a1 - 1], REG_SIZE);
	a2 = r_to_n(p->reg[a2 - 1], REG_SIZE);
	n_to_r(p->reg[a3 - 1], 4, a1 / a2);
	p->carry = 1;
}

void	op_mod(t_env *env, t_process *p, unsigned char arg[4][4], size_t *t)
{
	unsigned int	a1;
	unsigned int	a2;
	size_t			a3;

	(void)env;
	(void)t;
	p->carry = 0;
	a1 = r_to_n(arg[0], 1);
	a2 = r_to_n(arg[1], 1);
	a3 = r_to_n(arg[2], 1);
	if (!is_reg(a1) || !is_reg(a2) || !is_reg(a3))
		return ;
	a1 = r_to_n(p->reg[a1 - 1], REG_SIZE);
	a2 = r_to_n(p->reg[a2 - 1], REG_SIZE);
	n_to_r(p->reg[a3 - 1], 4, a1 % a2);
	p->carry = 1;
}

void	op_and(t_env *env, t_process *p, unsigned char arg[4][4], size_t *t)
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
	n_to_r(p->reg[a3 - 1], 4, a1 & a2);
	if (!(a1 & a2))
		p->carry = 1;
}
