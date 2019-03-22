/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 17:43:16 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/22 02:09:38 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
** __ATTENTION__
** Size == nb bits et NON nb octets
** Si on utilise sizeof il faut x8
*/

int16_t	ft_printhex(__uint128_t nb, uint8_t size, uint8_t format_0x)
{
	uint8_t		i;
	__uint128_t	one;

	i = 0;
	one = 1;
	if (size > 16)
		return (-1);
	if (format_0x == 'x')
		write(1, "0x", 2);
	// while (i < size)
	// {
		write(1,&nb,1);
	// }
	return (i);
}
