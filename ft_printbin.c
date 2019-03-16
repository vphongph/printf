/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 17:43:16 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/16 18:37:50 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/*
** __ATTENTION__
** Size == nb d'octets et pas de bits
** Renvoie == nb bits imprimés
*/

int16_t ft_printbin(__uint128_t nb, uint8_t size)
{
	uint8_t i;
	__uint128_t one;

	i = 0;
	one = 1;
	if (size > 16)
		return (-1);
	size <<= 3;
	while (i < size)
		nb & (one << (size - 1 - i++)) ? write (1, "1", 1) : write (1, "0", 1);
	return (size);
}