/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detectchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:09:39 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/22 02:16:08 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

/*
** _ATTENTION_ recherche 00, si 01 puis 00 (0x0100)
**			OU recherche c,	 si c-1 puis c (0x2223 pour c = '#')
** 			=> Les deux octects sont ON
** _ATTENTION_ si memsize > mem recherchée => fonction FAIL
** _ATTENTION_ endian
*/

int16_t	ft_printhex(__uint128_t nb, uint8_t size, uint8_t format_0x);

__uint128_t		detectchar(uint64_t mem, uint8_t memsize, uint8_t c)
{
	__uint128_t distribution;
	__uint128_t eighty;

	distribution = 1;
	eighty = 0x80;
	if (!(memsize <= 8 && memsize >= 1))
	{
		ft_putstr_fd_v2(RED BLINK"error detectchar\n"RESET, 2);
		return (0);
	}
	while (--memsize)
	{
		distribution = (distribution << 8) + 0x1;
		eighty = (eighty << 8) + 0x80;
	}

	mem = mem ^ (c * distribution);
	return ((mem - distribution) & ~mem & eighty);
}

int				main(void)
{
	uint64_t i = 18446744073709551615ULL;
	__int128_t j = i * 10;
j = 0;
	// printf(YELLOW"%#.16llx\n"RESET,detectchar(*(uint64_t *)"aaaaaaaa", 8, 'a'));
	    // printf(YELLOW"%llu\n"RESET,detectchar(*(uint64_t *)"aaaaaaaa", 8, 'a'));
										//    0xZZZZZZZZZZZZZZZZ
ft_printhex(42, 1, 'x');

	return (0);
}
