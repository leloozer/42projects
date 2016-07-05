/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:05:55 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/01 18:23:49 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdint.h>

void	ft_checkp(t_flag *tmp, va_list ap)
{
	char				*ptr;
	unsigned long long	nbr;
	int					i;

	nbr = 0;
	if (tmp->type == 'p')
	{
		nbr = va_arg(ap, unsigned long);
		if (tmp->precision != 0)
			tmp->zero = 0;
		ptr = ft_ulltoa_base(nbr, 16);
		i = ft_strlen(ptr);
		tmp->nbprint = tmp->nbprint + i;
		nbr = 0;
		if (tmp->precision > i)
		{
			nbr = tmp->precision - i;
			i = tmp->precision;
		}
		if ((tmp->width != 0) && (tmp->moins == 0) && (tmp->zero == 0))
			ft_lookwidth(tmp, i + 2);
		write(1, "0x", 2);
		tmp->nbprint = tmp->nbprint + 2;
		ft_checkpsuite(tmp, i, nbr, ptr);
	}
}

void	ft_checkpsuite(t_flag *tmp, int i, unsigned long long nbr, char *ptr)
{
	if ((tmp->width != 0) && (tmp->moins == 0) && (tmp->zero == 1))
		ft_lookwidth(tmp, (i + 2));
	if (tmp->precision != 0)
		ft_printprecision(tmp, nbr);
	ft_putstr(ptr);
	if ((tmp->moins == 1) && (tmp->width != 0))
		ft_lookwidth(tmp, i + 2);
}
