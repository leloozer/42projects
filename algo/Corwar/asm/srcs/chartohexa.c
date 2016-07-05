/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chartohexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:22:15 by mszczesn          #+#    #+#             */
/*   Updated: 2016/03/28 18:45:04 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_file	*ft_name(char *str, t_file *file)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	if (len > 128)
		ft_errorandexit(3);
	file->namechamp = ft_strdup(str);
	while (file->namechamp[i])
	{
		write(file->fd, &file->namechamp[i], sizeof(char));
		i++;
	}
	if ((lseek(file->fd, 136, SEEK_SET)) == -1)
		ft_errorandexit(7);
	return (file);
}

t_file	*ft_descr(char *str, t_file *file)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	if (len > 2048)
		ft_errorandexit(4);
	file->comchamp = ft_strdup(str);
	while (file->comchamp[i])
	{
		write(file->fd, &file->comchamp[i], sizeof(char));
		i++;
	}
	if ((lseek(file->fd, 144 + 2048, SEEK_SET)) == -1)
		ft_errorandexit(7);
	return (file);
}

t_file	*ft_size(char *str, t_file *file)
{
	unsigned int	i;

	i = 0;
	file->size = ft_atoi(str);
	i = ft_rev_uint(file->size);
	write(file->fd, &i, sizeof(unsigned int));
	return (file);
}

t_file	*ft_gotohexa(t_tlist *token_list, t_file *file)
{
	t_tlist		*tmp;

	tmp = token_list;
	while (tmp->next)
	{
		if (tmp->type == NAME)
			file = ft_name(tmp->content, file);
		else if (tmp->type == SIZE)
			file = ft_size(tmp->content, file);
		else if (tmp->type == DESCRIPTION)
			file = ft_descr(tmp->content, file);
		else if (tmp->type == INSTRUCTION || tmp->type == INSTRUCTION_SPE)
		{
			if (tmp->type == INSTRUCTION_SPE)
				file->instruc_spe = 1;
			else
				file->instruc_spe = 0;
			ft_opcode(tmp, file);
		}
		tmp = tmp->next;
	}
	return (file);
}
