/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 13:44:38 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/01 15:22:49 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <stdint.h>

void	ft_checkchar(t_flag *tmp, va_list ap)
{
	char	c;
	int		nbr;

	nbr = 1;
	if (tmp->type == 'c' && tmp->l == 1)
		tmp->type = 'C';
	if (tmp->type == 'c')
	{
		tmp->plus = 0;
		if (tmp->space == 1)
			tmp->width++;
		c = va_arg(ap, int);
		if (tmp->moins != 1)
			ft_lookwidth(tmp, nbr);
		ft_putchar(c);
		tmp->nbprint = tmp->nbprint + 1;
		if (tmp->moins == 1)
		{
			tmp->zero = 0;
			ft_lookwidth(tmp, nbr);
		}
	}
}
