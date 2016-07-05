/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modificator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 17:53:12 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/09 16:49:49 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdint.h>

void	ft_printmodificator(t_flag *tmp, void *nbr)
{
	if (tmp->l == 1)
		ft_putlnbr((long)nbr);
	else if (tmp->ll == 1)
		ft_putllnbr((long long)nbr);
	else if (tmp->h == 1)
		ft_puthnbr((short)nbr);
	else if (tmp->hh == 1)
		ft_puthhnbr((char)nbr);
	else if (tmp->z == 1)
		ft_putznbr((size_t)nbr);
	else if (tmp->j == 1)
		ft_putjnbr((intmax_t)nbr);
}

void	ft_putznbr(long long n)
{
	if (n > 9)
		ft_putznbr(n / 10);
	ft_putchar(n % 10 + '0');
}

void	ft_putlnbr(long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n < -9)
			ft_putlnbr(n / 10 * -1);
		ft_putchar(n % 10 * -1 + '0');
	}
	else
	{
		if (n > 9)
			ft_putlnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}

void	ft_putllnbr(long long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n < -9)
			ft_putllnbr(n / 10 * -1);
		ft_putchar(n % 10 * -1 + '0');
	}
	else
	{
		if (n > 9)
			ft_putllnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}

void	ft_puthnbr(short n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n < -9)
			ft_puthnbr(n / 10 * -1);
		ft_putchar(n % 10 * -1 + '0');
	}
	else
	{
		if (n > 9)
			ft_puthnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}
