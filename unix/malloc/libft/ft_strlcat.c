/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:49:23 by mszczesn          #+#    #+#             */
/*   Updated: 2015/11/24 10:56:58 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	nsrc;
	size_t	ndest;
	size_t	i;

	ndest = ft_strlen(dest);
	nsrc = ft_strlen(src);
	if (n < ndest)
		return (n + nsrc);
	i = 0;
	while (src[i] != '\0' && (ndest + i + 1) < n)
	{
		dest[ndest + i] = src[i];
		i++;
	}
	dest[ndest + i] = '\0';
	return (ndest + nsrc);
}
