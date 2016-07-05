/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkoO.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 14:02:46 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/01 13:10:29 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdint.h>

void	ft_checkoO(t_flag *tmp, va_list ap)
{
	char *str;
	int i;
	int j;

	j = 0;
	if (tmp->type == 'o' || tmp->type == 'O')
	{
		if (tmp->type == 'O')
			ft_modifmaj(tmp);
		if (tmp->moins == 1 || tmp->precision != 0)
		{
			tmp->zero = 0;
		}
		if ((tmp->hh || tmp->h || tmp->l || tmp->ll || tmp->j || tmp->z) == 1)
			str = ft_toa_basemodif(tmp, ap, 8);
		if ((tmp->hh || tmp->h || tmp->l || tmp->ll || tmp->j || tmp->z) == 0)
			str = ft_lltoa_base((va_arg(ap, unsigned int)), 8);
		i = ft_strlen(str);
		tmp->nbprint = tmp->nbprint + i;
		if (tmp->precision > i)
		{
			if (tmp->moins == 1)
				tmp->sharp = 0;
			j = tmp->precision - i;
			i = tmp->precision;
		}
		if (tmp->width != 0 && tmp->moins == 0)
			ft_lookwidthO(tmp, i);
		if (tmp->sharp == 1)
		{
			write(1, "0", 1);
			tmp->nbprint = tmp->nbprint + 1;
		}
		if (tmp->precision != 0)
			ft_printprecision(tmp, j);
		ft_putstr(str);
		if (tmp->width != 0 && tmp->moins == 1)
			ft_lookwidthO(tmp, i);
	}
}

void ft_lookwidthO(t_flag *tmp, int i)
{
	if (tmp->sharp == 1)
		i++;
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
