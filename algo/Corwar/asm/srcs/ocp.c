/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 15:20:46 by mszczesn          #+#    #+#             */
/*   Updated: 2016/04/06 23:37:49 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

unsigned int	ft_ocptowrite2(t_tlist *tmp, unsigned int ocp)
{
	if (tmp->type == PARAM_REG)
		ocp = ocp + 16;
	else if (tmp->type == PARAM_DIR || tmp->type == PARAM_LABEL_DIR)
		ocp = ocp + 32;
	else if (tmp->type == PARAM_IND || tmp->type == PARAM_LABEL_IND)
		ocp = ocp + 48;
	tmp = tmp->next;
	if (tmp && tmp->type != INSTRUCTION && tmp->type != INSTRUCTION_SPE)
	{
		if (tmp->type == PARAM_REG)
			ocp = ocp + 4;
		else if (tmp->type == PARAM_DIR || tmp->type == PARAM_LABEL_DIR)
			ocp = ocp + 8;
		else if (tmp->type == PARAM_IND || tmp->type == PARAM_LABEL_IND)
			ocp = ocp + 12;
	}
	return (ocp);
}

char			*ft_no_r(char *str)
{
	char	*s;
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (str == NULL)
		return (NULL);
	s = (char *)malloc(sizeof(char) * ft_strlen(str));
	while (str[i] != '\0')
	{
		s[j] = str[i];
		i++;
		j++;
	}
	s[j] = '\0';
	return (s);
}

void			ft_instrucnospe(t_tlist *tmp, t_file *file, unsigned int i)
{
	if (tmp->type == PARAM_REG)
	{
		i = ft_atoi(ft_no_r(tmp->content));
		write(file->fd, &i, sizeof(char));
	}
	else if (tmp->type == PARAM_DIR || tmp->type == PARAM_LABEL_DIR)
	{
		i = ft_rev_uint(ft_atoi(tmp->content));
		if (tmp->type == PARAM_LABEL_DIR)
			i = ft_rev_uint(tmp->addr);
		write(file->fd, &i, sizeof(unsigned int));
	}
	else if (tmp->type == PARAM_IND)
	{
		i = ft_rev_usint((unsigned short int)ft_atoi(tmp->content));
		write(file->fd, &i, sizeof(unsigned short int));
	}
	else if (tmp->type == PARAM_LABEL_IND)
	{
		i = ft_rev_usint((unsigned short int)tmp->addr);
		write(file->fd, &i, sizeof(unsigned short int));
	}
	else
		return ;
}

void			ft_instrucspe(t_tlist *tmp, t_file *file, unsigned int i)
{
	if (tmp->type == PARAM_REG)
	{
		i = ft_atoi(ft_no_r(tmp->content));
		write(file->fd, &i, sizeof(char));
	}
	else if (tmp->type == PARAM_DIR || tmp->type == PARAM_IND)
	{
		i = ft_rev_usint((unsigned short int)ft_atoi(tmp->content));
		write(file->fd, &i, sizeof(unsigned short int));
	}
	else if (tmp->type == PARAM_LABEL_DIR)
	{
		i = ft_rev_usint((unsigned short int)tmp->addr);
		write(file->fd, &i, sizeof(unsigned short int));
	}
	else if (tmp->type == PARAM_LABEL_IND)
	{
		i = ft_rev_usint((unsigned short int)tmp->addr);
		write(file->fd, &i, sizeof(unsigned short int));
	}
	else
		return ;
}

void			ft_printinstruc(t_tlist *tmp, t_file *file)
{
	char			*str;
	unsigned int	i;

	str = NULL;
	i = 0;
	if (tmp->type == ENDL)
		return ;
	if (file->instruc_spe == 0)
		ft_instrucnospe(tmp, file, i);
	if (file->instruc_spe == 1)
		ft_instrucspe(tmp, file, i);
}
