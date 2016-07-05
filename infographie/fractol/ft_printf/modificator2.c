/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modificator2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 16:52:30 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/09 16:49:32 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int		ft_lenmodif(t_flag *tmp, void *nbr)
{
	int i;

	i = 0;
	if (tmp->hh == 1)
		i = ft_len((char)nbr);
	else if (tmp->h == 1)
		i = ft_len((short)nbr);
	else if (tmp->l == 1)
		i = ft_len((long)nbr);
	else if (tmp->ll == 1)
		i = ft_len((long long)nbr);
	else if (tmp->j == 1)
		i = ft_len((intmax_t)nbr);
	else if (tmp->z == 1)
		i = ft_len((size_t)nbr);
	return (i);
}

void	ft_modifmaj(t_flag *tmp)
{
	if (tmp->type == 'D')
		tmp->type = 'd';
	if (tmp->type == 'O')
		tmp->type = 'o';
	if (tmp->type == 'U')
		tmp->type = 'u';
	tmp->hh = 0;
	tmp->h = 0;
	tmp->l = 1;
	tmp->ll = 0;
	tmp->z = 0;
	tmp->j = 0;
}

char	*ft_toa_basemodif(t_flag *tmp, va_list ap, int base)
{
	char *str;

	str = NULL;
	if (tmp->hh == 1 && (tmp->type == 'x' || tmp->type == 'o'))
		str = ft_lltoa_base(((unsigned char)va_arg(ap, int)), base);
	else if (tmp->hh == 1 && (tmp->type == 'X' || tmp->type == 'O'))
		str = ft_lltoa_basemaj(((unsigned char)va_arg(ap, int)), base);
	else if (tmp->h == 1 && (tmp->type == 'x' || tmp->type == 'o'))
		str = ft_lltoa_base(((unsigned short int)va_arg(ap, int)), base);
	else if (tmp->h == 1 && (tmp->type == 'X' || tmp->type == 'O'))
		str = ft_lltoa_basemaj(((unsigned short int)va_arg(ap, int)), base);
	else if ((tmp->l == 1 || tmp->j == 1) &&
			(tmp->type == 'x' || tmp->type == 'o'))
		str = ft_ultoa_base(va_arg(ap, unsigned long int), base);
	else if ((tmp->l == 1 || tmp->j == 1) &&
			(tmp->type == 'X' || tmp->type == 'O'))
		str = ft_ultoa_basemaj(va_arg(ap, unsigned long int), base);
	else if ((tmp->ll == 1 || tmp->z == 1) &&
			(tmp->type == 'x' || tmp->type == 'o'))
		str = ft_ulltoa_base(va_arg(ap, unsigned long long), base);
	else if ((tmp->ll == 1 || tmp->z == 1) &&
			(tmp->type == 'X' || tmp->type == 'O'))
		str = ft_ulltoa_basemaj(va_arg(ap, unsigned long long), base);
	return (str);
}

void	ft_puthhnbr(long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n < -9)
			ft_puthhnbr(n / 10 * -1);
		ft_putchar(n % 10 * -1 + '0');
	}
	else
	{
		if (n > 9)
			ft_puthhnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}

void	ft_putjnbr(long long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n < -9)
			ft_putjnbr(n / 10 * -1);
		ft_putchar(n % 10 * -1 + '0');
	}
	else
	{
		if (n > 9)
			ft_putjnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}
