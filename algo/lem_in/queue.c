/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 11:23:29 by mszczesn          #+#    #+#             */
/*   Updated: 2016/03/04 16:43:10 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_initqueue(t_queue *queue)
{
	queue->next = NULL;
	queue->output = NULL;
	queue->ok = 0;
}

t_room	*ft_initroom(t_room *room)
{
	int i;

	i = 0;
	if ((room = (t_room *)malloc(sizeof(t_room))) != NULL)
	{
		room->name = NULL;
		room->x = 0;
		room->y = 0;
		room->flag = 0;
		room->fils = 0;
		while (i <= 300)
		{
			room->prev[i] = NULL;
			room->next[i] = NULL;
			i++;
		}
		return (room);
	}
	return (NULL);
}

void	ft_firstqueue(t_queue *queue, t_room *room)
{
	queue->output = room;
	queue->next = NULL;
	queue->ok = 0;
}

void	ft_addinput(t_queue *queue, t_room *room)
{
	t_queue *tmp;
	t_queue *new;

	new = (t_queue *)malloc(sizeof(t_queue));
	tmp = queue;
	while (queue->next != NULL)
		queue = queue->next;
	new->output = room;
	new->ok = 0;
	new->next = NULL;
	queue->next = new;
	queue = tmp;
}
