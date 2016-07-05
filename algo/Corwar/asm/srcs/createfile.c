/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:20:12 by mszczesn          #+#    #+#             */
/*   Updated: 2016/03/28 18:35:05 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

unsigned int		ft_rev_uint(unsigned int n)
{
	unsigned char	*t;

	t = (unsigned char*)&n;
	return (0
			| (unsigned int)t[0] << 24
			| (unsigned int)t[1] << 16
			| (unsigned int)t[2] << 8
			| (unsigned int)t[3]);
}

unsigned short int	ft_rev_usint(unsigned short int n)
{
	unsigned char	*t;

	t = (unsigned char*)&n;
	return (0
			| (unsigned short int)t[0] << 8
			| (unsigned short int)t[1]);
}

t_file				*ft_initfile(t_file *file)
{
	if ((file = (t_file *)malloc(sizeof(t_file))) == NULL)
		return (NULL);
	file->name = NULL;
	file->namechamp = NULL;
	file->comchamp = NULL;
	file->content = NULL;
	file->size = 0;
	file->fd = 0;
	file->instruc_spe = 0;
	return (file);
}

t_file				*ft_goodnamefile(t_file *file)
{
	int		len;

	len = 0;
	file->name = ft_strrev(file->name);
	len = ft_strlen(file->name);
	len--;
	file->name = ft_strsub(file->name, 0, len);
	file->name = ft_strjoin(file->name, "cor");
	return (file);
}

t_file				*ft_createfile(t_file *file)
{
	int				i;
	unsigned int	begin;

	i = 0;
	begin = ft_rev_uint(COREWAR_EXEC_MAGIC);
	file = ft_goodnamefile(file);
	if ((file->fd = open(file->name, O_CREAT | O_WRONLY, 0644)) == -1)
		ft_errorandexit(7);
	write(file->fd, &begin, sizeof(unsigned int));
	return (file);
}
