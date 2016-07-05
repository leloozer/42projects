/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcodetofile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:21:56 by mszczesn          #+#    #+#             */
/*   Updated: 2016/03/29 21:26:15 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

unsigned int	ft_opcodetowrite2(char *str, unsigned int opcode)
{
	if ((ft_strcmp(str, "zjmp")) == 0)
		opcode = 9;
	else if ((ft_strcmp(str, "ldi")) == 0)
		opcode = 10;
	else if ((ft_strcmp(str, "sti")) == 0)
		opcode = 11;
	else if ((ft_strcmp(str, "fork")) == 0)
		opcode = 12;
	else if ((ft_strcmp(str, "lld")) == 0)
		opcode = 13;
	else if ((ft_strcmp(str, "lldi")) == 0)
		opcode = 14;
	else if ((ft_strcmp(str, "lfork")) == 0)
		opcode = 15;
	else if ((ft_strcmp(str, "aff")) == 0)
		opcode = 16;
	else if ((ft_strcmp(str, "mul")) == 0)
		opcode = 17;
	else if ((ft_strcmp(str, "div")) == 0)
		opcode = 18;
	else if ((ft_strcmp(str, "mod")) == 0)
		opcode = 19;
	else
		ft_errorandexit(5);
	return (opcode);
}

unsigned int	ft_opcodetowrite(char *str)
{
	unsigned int	opcode;

	opcode = 0;
	if ((ft_strcmp(str, "live")) == 0)
		opcode = 1;
	else if ((ft_strcmp(str, "ld")) == 0)
		opcode = 2;
	else if ((ft_strcmp(str, "st")) == 0)
		opcode = 3;
	else if ((ft_strcmp(str, "add")) == 0)
		opcode = 4;
	else if ((ft_strcmp(str, "sub")) == 0)
		opcode = 5;
	else if ((ft_strcmp(str, "and")) == 0)
		opcode = 6;
	else if ((ft_strcmp(str, "or")) == 0)
		opcode = 7;
	else if ((ft_strcmp(str, "xor")) == 0)
		opcode = 8;
	else
		opcode = ft_opcodetowrite2(str, opcode);
	return (opcode);
}

t_tlist			*ft_ocptowrite(t_tlist *token_list, t_file *file)
{
	t_tlist				*tmp;
	t_tlist				*plist;
	unsigned int		ocp;

	ocp = 0;
	tmp = token_list;
	plist = token_list;
	tmp = tmp->next;
	if ((tmp->type != INSTRUCTION && tmp->type != INSTRUCTION_SPE) &&
			(tmp->type == PARAM_REG))
		ocp = 64;
	else if ((tmp->type != INSTRUCTION && tmp->type != INSTRUCTION_SPE) &&
			(tmp->type == PARAM_DIR || tmp->type == PARAM_LABEL_DIR))
		ocp = 128;
	else if ((tmp->type != INSTRUCTION && tmp->type != INSTRUCTION_SPE) &&
			(tmp->type == PARAM_IND || tmp->type == PARAM_LABEL_IND))
		ocp = 192;
	tmp = tmp->next;
	if (tmp->type != INSTRUCTION && tmp->type != INSTRUCTION_SPE)
		ocp = ft_ocptowrite2(tmp, ocp);
	write(file->fd, &ocp, sizeof(char));
	token_list = plist;
	return (token_list);
}

t_tlist			*ft_opcode(t_tlist *token_list, t_file *file)
{
	t_tlist			*tmp;
	unsigned int	opcode;

	tmp = token_list;
	opcode = ft_opcodetowrite(token_list->content);
	write(file->fd, &opcode, sizeof(char));
	if (token_list->has_ocp == 1)
		tmp = ft_ocptowrite(token_list, file);
	tmp = tmp->next;
	while (tmp->next && tmp->type != INSTRUCTION && tmp->type
		!= INSTRUCTION_SPE)
	{
		ft_printinstruc(tmp, file);
		tmp = tmp->next;
	}
	return (tmp);
}
