/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:00:19 by mszczesn          #+#    #+#             */
/*   Updated: 2015/11/26 15:26:05 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	void	*cp;

	cp = malloc(len);
	ft_memcpy(cp, src, len);
	ft_memcpy(dest, cp, len);
	free(cp);
	return (dest);
}
