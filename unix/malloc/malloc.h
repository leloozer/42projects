/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 16:43:41 by mszczesn          #+#    #+#             */
/*   Updated: 2016/07/20 16:22:36 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# define TINY 128 // de 1 a TINY bytes
# define SMALL 131072 // de Tiny a SMALL bytes
# define LARGE // de SMALL a +

#include <sys/mman.h>
#include <sys/time.h>
#include <sys/resource.h>

#include <unistd.h>
#include <stdlib.h>

typedef		struct s_meta
{
	size_t	size;
	struct	s_meta *next;
	int		free;
	int		magic;
}				t_meta;

void	ft_free(void *ptr);
void	*ft_malloc(size_t size);
void	*ft_realloc(void *ptr, size_t size);

void	show_alloc_mem();

#endif
