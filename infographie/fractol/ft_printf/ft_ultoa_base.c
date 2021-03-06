/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 12:12:56 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/01 19:19:11 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

unsigned long	ft_ulenght(unsigned long n, unsigned int base)
{
	int i;

	i = 0;
	while (n > base - 1)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char			*ft_ultoa_base(unsigned long n, unsigned int base)
{
	static char	*num;
	char		*str;
	int			i;

	num = "0123456789abcdefghijklmnopqrstuvwxyz";
	i = ft_ulenght(n, base);
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	if (base < 2 || base > 35)
	{
		str[i] = '\0';
		return (str);
	}
	while (n > 0)
	{
		str[i] = num[n % base];
		n /= base;
		i--;
	}
	return (str);
}
