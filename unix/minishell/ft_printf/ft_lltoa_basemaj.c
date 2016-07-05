/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_basemaj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:02:02 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/01 18:46:44 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

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
	return (i);
}

char		*ft_lltoa_basemaj(long long n, int base)
{
	static char	*num;
	char		*str;
	int			i;

	num = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	i = ft_lenght(n, base);
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	if (base < 2 || base > 35)
	{
		str[i] = '\0';
		return (str);
	}
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
