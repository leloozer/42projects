/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 16:31:45 by mszczesn          #+#    #+#             */
/*   Updated: 2016/06/10 16:32:05 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	if (str == NULL)
		return (NULL);
	j = ft_strlen(str) - 1;
	tmp = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	while (j >= 0)
	{
		tmp[i] = str[j];
		i++;
		j--;
	}
	tmp[i] = '\0';
	return (tmp);
}
