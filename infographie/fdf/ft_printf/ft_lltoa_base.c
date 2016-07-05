/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:01:44 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/09 17:03:18 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_lenght(long long n, int base)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > base - 1)
	{
		n = n / base;
		i++;
	}
	if (n == 0)
		i++;
	return (i);
}

char		*ft_lltoa_base(long long n, int base)
{
	static char	*num;
	char		*str;
	int			i;

	num = "0123456789abcdefghijklmnopqrstuvwxyz";
	i = ft_lenght(n, base);
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	if (base < 2 || base > 35)
	{
		str[i] = '\0';
		return (str);
	}
	if (n == 0)
		str = "0\0";
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		str[i] = num[n % base];
		n /= base;
		i--;
	}
	return (str);
}
