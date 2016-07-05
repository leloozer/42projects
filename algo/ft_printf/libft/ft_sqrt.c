/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 18:01:00 by mszczesn          #+#    #+#             */
/*   Updated: 2015/12/03 18:55:37 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int a)
{
	int	result;

	result = 0;
	if (a < 0)
	{
		ft_putstr("Error: negative number\n");
		return (0);
	}
	while ((result * result) < a)
		result++;
	return (result);
}
