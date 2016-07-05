/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deltub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 17:05:30 by mszczesn          #+#    #+#             */
/*   Updated: 2016/02/17 20:46:56 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

void	ft_deltub(t_param *env, int position)
{
	env->tub = env->tub->prev;
	printf("env->nbr : %d , position : %d \n", env->tub->nbr, position);
//	while (env->tub->nbr != position)
//	{
//		env->tub = env->tub->next;
//	printf("T1 : %s , T2 : %s \n", env->tub->T_1, env->tub->T_2);
//	}
	write(1, "ok\n", 3);
	//env->tub = env->tub->prev;
	env->tub->next = env->tub->next->next;
	env->tub->next->prev = env->tub->prev;
}
