/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:53:02 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/01 19:14:23 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdint.h>

void	ft_checku(t_flag *tmp, va_list ap)
{
	int				nbr;
	int				len;
	size_t			nbrz;
	unsigned char	nbrhh;

	nbr = 0;
	if (tmp->type == 'u' || tmp->type == 'U')
	{
		ft_tmpforu(tmp);
		if (tmp->z == 0 && tmp->hh == 0)
			nbr = va_arg(ap, unsigned int);
		if (tmp->z == 1)
			nbrz = va_arg(ap, size_t);
		if (tmp->hh == 1)
			nbrhh = va_arg(ap, int);
		if (nbr < 0 && tmp->z == 0)
			ft_nbrneg(tmp, nbr);
		if (nbr >= 0)
		{
			len = ft_lenu(tmp, nbr, nbrz, nbrhh);
			len = ft_nbrpos(tmp, len);
			ft_printu(tmp, nbr, nbrz, nbrhh);
			ft_umoins(tmp, len);
		}
	}
}

void	ft_nbrneg(t_flag *tmp, int nbr)
{
	unsigned long int	max;
	int					len;
	int					lenprecision;

	lenprecision = 0;
	max = 4294967295;
	nbr = nbr * -1;
	max = max - nbr + 1;
	len = ft_lenuint(max);
	tmp->nbprint = tmp->nbprint + len;
	if (tmp->precision > len)
	{
		lenprecision = tmp->precision - len;
		len = tmp->precision;
	}
	if (tmp->moins == 0)
		ft_lookwidth(tmp, len);
	if (tmp->precision != 0)
		ft_printprecision(tmp, lenprecision);
	ft_putnbruint(max);
	if (tmp->moins == 1)
	{
		tmp->zero = 0;
		ft_lookwidth(tmp, len);
	}
}

void	ft_forz(t_flag *tmp, size_t nbr)
{
	unsigned long int	max;
	int					len;
	int					lenprecision;

	max = 4294967295;
	lenprecision = 0;
	nbr = nbr * -1;
	if (tmp->type == 'u')
		max = max + nbr + 1;
	if (tmp->type == 'U')
		max = max * 2 + nbr + 1;
	len = ft_lenuint(max);
	tmp->nbprint = tmp->nbprint + len;
	if (tmp->precision > len)
	{
		lenprecision = tmp->precision - len;
		len = tmp->precision;
	}
	if (tmp->moins == 0)
		ft_lookwidth(tmp, len);
	if (tmp->precision != 0)
		ft_printprecision(tmp, lenprecision);
	ft_putnbruint(max);
	ft_umoins(tmp, len);
}

int		ft_lenuint(unsigned int max)
{
	int i;

	i = 0;
	while (max > 9)
	{
		max = max / 10;
		i++;
	}
	i++;
	return (i);
}
