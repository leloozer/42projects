/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszczesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 12:13:08 by mszczesn          #+#    #+#             */
/*   Updated: 2016/03/24 13:19:00 by mszczesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int main(void)
{
	char*a="#include <stdio.h>\n int main(void)\n{\n	char*a=%c%s%s;\nprintf(a,10,34,a,3);\n}\n";
	printf(a,10,34,a,34);
}