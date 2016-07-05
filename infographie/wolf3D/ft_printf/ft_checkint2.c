/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkint2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 14:54:13 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/01 18:37:54 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_checkintsuite(t_flag *tmp, int len, int lenprecision, void *nbr)
{
	if (tmp->moins == 0)
		ft_lookwidth(tmp, len);
	ft_printplus_spaceint(tmp, (int)nbr);
	if (tmp->precision != 0)
		ft_printprecision(tmp, lenprecision);
	if ((tmp->hh || tmp->h || tmp->l || tmp->ll || tmp->j || tmp->z) == 1)
		ft_printmodificator(tmp, nbr);
	if ((tmp->hh || tmp->h || tmp->l || tmp->ll || tmp->j || tmp->z) == 0)
		ft_putnbr((int)nbr);
	if (tmp->moins == 1)
	{
		tmp->zero = 0;
		ft_lookwidth(tmp, len);
	}
}

void	ft_lookwidthsuite(t_flag *tmp)
{
	while (tmp->width > 0)
	{
		ft_putchar('0');
		tmp->nbprint = tmp->nbprint + 1;
		tmp->width = tmp->width - 1;
	}
}
