/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:28:18 by rmorel            #+#    #+#             */
/*   Updated: 2016/03/29 21:04:02 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	load_a(unsigned char a[4], t_env *env, size_t pos, size_t size)
{
	int	i;

	i = -1;
	while (++i < 4)
		a[i] = 0;
	while (size)
	{
		a[size - 1] = env->mem[mod_mem(pos + size)];
		size--;
	}
}

void	load_args(unsigned char arg[4][4], t_env *env, size_t pc)
{
	unsigned char	op;
	unsigned char	ocp;
	unsigned char	size[3];

	op = env->mem[pc];
	ocp = env->mem[mod_mem(pc + 1)];
	arg[3][0] = arg_size((ocp >> 6) & 0x3);
	arg[3][1] = arg_size((ocp >> 4) & 0x3);
	arg[3][2] = arg_size((ocp >> 2) & 0x3);
	size[0] = proper_size(arg[3][0], op);
	size[1] = proper_size(arg[3][1], op);
	size[2] = proper_size(arg[3][2], op);
	load_a(arg[0], env, pc + 1, size[0]);
	load_a(arg[1], env, pc + 1 + size[0], size[1]);
	load_a(arg[2], env, pc + 1 + size[0] + size[1], size[2]);
	arg[3][3] = get_offset(size) + 1;
}

void	load_args2(unsigned char arg[4][4], t_env *env, size_t pc)
{
	unsigned char	op;

	op = env->mem[pc];
	arg[3][0] = 4;
	arg[3][1] = 0;
	arg[3][2] = 0;
	arg[3][3] = proper_size(arg[3][0], op);
	load_a(arg[0], env, pc, arg[3][3]);
}

void	select_op(t_env *env, t_process *p, unsigned char arg[4][4], size_t op)
{
	size_t	t[3];

	t[0] = arg[3][0];
	t[1] = arg[3][1];
	t[2] = arg[3][2];
	g_op_exec[0] = op_live;
	g_op_exec[1] = op_ld;
	g_op_exec[2] = op_st;
	g_op_exec[3] = op_add;
	g_op_exec[4] = op_sub;
	g_op_exec[5] = op_and;
	g_op_exec[6] = op_or;
	g_op_exec[7] = op_xor;
	g_op_exec[8] = op_zjmp;
	g_op_exec[9] = op_ldi;
	g_op_exec[10] = op_sti;
	g_op_exec[11] = op_fork;
	g_op_exec[12] = op_lld;
	g_op_exec[13] = op_lldi;
	g_op_exec[14] = op_lfork;
	g_op_exec[15] = op_aff;
	g_op_exec[16] = op_mul;
	g_op_exec[17] = op_div;
	g_op_exec[18] = op_mod;
	g_op_exec[op](env, p, arg, t);
}

void	exec_op(t_env *env, t_process *p)
{
	size_t			op;
	unsigned char	arg[4][4];

	op = env->mem[p->pc];
	if (!valid_op(op))
	{
		p->pc++;
		return ;
	}
	op--;
	if (g_op_tab[op].has_ocp)
		load_args(arg, env, p->pc);
	else
		load_args2(arg, env, p->pc);
	select_op(env, p, arg, op);
	if (op != 8)
		p->pc = mod_mem(p->pc + arg[3][3] + 1);
}
