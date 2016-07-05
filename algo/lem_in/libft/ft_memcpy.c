/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:46:15 by mszczesn          #+#    #+#             */
/*   Updated: 2015/11/25 14:57:08 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*de;
	char		*s;

	i = 0;
	de = (char *)dest;
	s = (char *)src;
	while (i < n)
	{
		de[i] = s[i];
		i++;
	}
	return (de);
}
