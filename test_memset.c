/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:36:31 by vphongph          #+#    #+#             */
/*   Updated: 2019/04/07 19:38:39 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

#define DISTRIB_INT128_INT64 ((__uint128_t)0x0000000000000001 * 0x1000000000000000 * 0x10 + 0x0000000000000001)
#define DISTRIB_INT128_INT32 ((__uint128_t)0x0000000100000001 * 0x100000000 * 0x100000000 + 0x0000000100000001)
#define DISTRIB_INT128_INT16 ((__uint128_t)0x0001000100010001 * 0x1000000000000 * 0x10000 + 0x0001000100010001)
#define DISTRIB_INT128_INT8 ((__uint128_t)0x0101010101010101 * 0x100000000000000 * 0x100 + 0x0101010101010101)



void	*ft_memset(void *b, int c, size_t len);

int main(void)
{
	int16_t tab[64]; (void)tab;
	// f	t_memset(tab, 0x7f , sizeof(tab));
	// ft_bzero_v2(tab, sizeof(tab));
	//
	int i = 0; (void)i;
	//
	// while ((unsigned int)i < sizeof(tab) / sizeof(__uint128_t))
	// {
	// 	((__uint128_t *)tab)[i] = 16446 * DISTRIB_INT128_INT16;
	// 	i++;
	// }
	//
	// i = 0;
	// while (i < 	64)
	// {
	// 	printf("%c\n", tab[i]);
	// 	i++;
	// }

	return (0);
}
