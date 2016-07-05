/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:46:25 by mszczesn          #+#    #+#             */
/*   Updated: 2015/11/27 11:05:17 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	char		*de;
	const char	*s;

	i = 0;
	de = (char *)dest;
	s = (const char *)src;
	while (i < n)
	{
		de[i] = s[i];
		if (s[i] == (char)c)
			return ((void *)(de + i + 1));
		i++;
	}
	return (NULL);
}
