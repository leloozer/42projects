/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 16:47:41 by mszczesn          #+#    #+#             */
/*   Updated: 2016/07/11 19:30:16 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*ft_malloc(size_t size)
{
	void *ptr;

	ptr = mmap(0, size, PROT_READ | PROT_WRITE, )

}

int main()
{
	int i;
	char *add;

	i = 0;
	while(i < 1024)
	{
		add = (char *)ft_malloc(1024);
		add[0] = 42;
		i++;
	}
	return (0);
}
