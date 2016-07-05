/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:28:25 by rmorel            #+#    #+#             */
/*   Updated: 2016/03/29 21:03:12 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_fork(t_env *env, t_process *p, unsigned char arg[4][4], size_t *t)
{
	size_t	i;
	size_t	j;

	(void)t;
	add_process(mod_idx(r_to_n(arg[0], 2), p, 2), 0, env);
	env->p_list->carry = p->carry;
	i = 0;
	while (i < REG_NUMBER)
	{
		j = 0;
		while (j < REG_SIZE)
		{
			env->p_list->reg[i][j] = p->reg[i][j];
			j++;
		}
		i++;
	}
}

void	op_lld(t_env *env, t_process *p, unsigned char arg[4][4], size_t *t)
{
	size_t	a1;
	size_t	a2;

	p->carry = 0;
	a2 = r_to_n(arg[1], 1);
	if (!is_reg(a2))
		return ;
	a1 = r_to_n(arg[0], 4);
	if (t[0] == 2)
		a1 = mem_to_n(env->mem, a1 + p->pc, 4);
	n_to_r(p->reg[a2 - 1], REG_SIZE, a1);
	p->carry = 1;
}

void	op_lldi(t_env *env, t_process *p, unsigned char arg[4][4], size_t *t)
{
	unsigned int	a1;
	unsigned int	a2;
	size_t			a3;
	size_t			val;

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
		a1 = mem_to_n(env->mem, mod_mem(a1) + p->pc, 4);
	if (t[1] == 1)
		a2 = r_to_n(p->reg[a2 - 1], REG_SIZE);
	val = mem_to_n(env->mem, mod_mem(a1 + a2) + p->pc, 4);
	n_to_r(p->reg[a3 - 1], 4, val);
	p->carry = 1;
}

void	op_lfork(t_env *env, t_process *p, unsigned char arg[4][4], size_t *t)
{
	size_t	i;
	size_t	j;

	(void)t;
	add_process(mod_mem(r_to_n(arg[0], 2)), 0, env);
	env->p_list->carry = p->carry;
	i = 0;
	while (i < REG_NUMBER)
	{
		j = 0;
		while (j < REG_SIZE)
		{
			env->p_list->reg[i][j] = p->reg[i][j];
			j++;
		}
		i++;
	}
}

void	op_aff(t_env *env, t_process *p, unsigned char arg[4][4], size_t *t)
{
	unsigned char a1;

	(void)env;
	(void)t;
	a1 = r_to_n(arg[0], 1);
	if (!is_reg(a1))
		return ;
	ft_putchar((char)r_to_n(p->reg[a1 - 1], REG_SIZE));
}
