/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_to_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:28:18 by rmorel            #+#    #+#             */
/*   Updated: 2016/03/10 16:28:20 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	put_hex(unsigned char c)
{
	size_t h1;
	size_t h2;

	h1 = c / 16;
	h2 = c - (h1 * 16);
	write(1, &"0123456789ABCDEF"[h1], 1);
	write(1, &"0123456789ABCDEF"[h2], 1);
}

void	get_hexa(char tab[3], t_env *env, int i)
{
	size_t		h1;
	size_t		h2;

	h1 = env->mem[i] / 16;
	h2 = env->mem[i] - (h1 * 16);
	tab[0] = "0123456789ABCDEF"[h1];
	tab[1] = "0123456789ABCDEF"[h2];
	tab[2] = '\0';
}

void	hexdump(unsigned char *data, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		put_hex(data[i]);
		i++;
		if (i % 32 == 0)
			ft_putchar('\n');
		else
			ft_putchar(' ');
	}
}
