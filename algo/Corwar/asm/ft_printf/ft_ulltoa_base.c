/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 16:55:36 by mszczesn          #+#    #+#             */
/*   Updated: 2016/03/11 19:05:16 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned long	ft_ullenght(unsigned long long n, unsigned int base)
{
	int i;

	i = 0;
	while (n > (base - 1))
	{
		n = n / base;
		i++;
	}
	return (i);
}

char			*ft_ulltoa_base(unsigned long long n, unsigned int base)
{
	static char	*num;
	char		*str;
	int			i;

	num = "0123456789abcdefghijklmnopqrstuvwxyz";
	i = ft_ullenght(n, base);
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
