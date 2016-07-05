/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:49:03 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/01 15:50:16 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdint.h>

void	ft_checkx(t_flag *tmp, va_list ap)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	str = NULL;
	if (tmp->type == 'x' || tmp->type == 'X')
	{
		if (tmp->precision != 0 || tmp->moins == 1)
			tmp->zero = 0;
		if ((tmp->hh || tmp->h || tmp->l || tmp->ll || tmp->j || tmp->z) == 1)
			str = ft_toa_basemodif(tmp, ap, 16);
		if ((tmp->hh || tmp->h || tmp->l || tmp->ll || tmp->j || tmp->z) == 0)
		{
			if (tmp->type == 'x')
				str = ft_lltoa_base(va_arg(ap, unsigned int), 16);
			if (tmp->type == 'X')
				str = ft_lltoa_basemaj(va_arg(ap, unsigned int), 16);
		}
		i = ft_strlen(str);
		tmp->nbprint = tmp->nbprint + i;
		ft_checkxsuite(tmp, i, j, str);
	}
}

void	ft_checkxsuite(t_flag *tmp, int i, int j, char *str)
{
	if (tmp->precision > i)
	{
		j = tmp->precision - i;
		i = tmp->precision;
	}
	if ((tmp->width != 0) && (tmp->moins == 0) && (tmp->zero == 0))
		ft_lookwidthx(tmp, i);
	if ((tmp->sharp == 1) && (tmp->type == 'x'))
	{
		write(1, "0x", 2);
		tmp->nbprint = tmp->nbprint + 2;
	}
	if ((tmp->sharp == 1) && (tmp->type == 'X'))
	{
		write(1, "0X", 2);
		tmp->nbprint = tmp->nbprint + 2;
	}
	if ((tmp->width != 0) && (tmp->moins == 0) && (tmp->zero == 1))
		ft_lookwidthx(tmp, i);
	if (tmp->precision != 0)
		ft_printprecision(tmp, j);
	ft_putstr(str);
	if ((tmp->moins == 1) && (tmp->width != 0))
		ft_lookwidthx(tmp, i);
}

void	ft_lookwidthx(t_flag *tmp, int i)
{
	if (tmp->sharp == 1)
		i = i + 2;
	tmp->width = tmp->width - i;
	while ((tmp->width > 0) && (tmp->zero == 0))
	{
		ft_putchar(' ');
		tmp->nbprint = tmp->nbprint + 1;
		tmp->width = tmp->width - 1;
	}
	while ((tmp->width > 0) && (tmp->zero == 1))
	{
		ft_putchar('0');
		tmp->nbprint = tmp->nbprint + 1;
		tmp->width = tmp->width - 1;
	}
}
