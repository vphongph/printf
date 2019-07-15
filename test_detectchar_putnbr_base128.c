/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_detectchar_putnbr_base128.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:09:39 by vphongph          #+#    #+#             */
/*   Updated: 2019/04/01 16:29:28 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int				main(void)
{
	__uint128_t j = (__uint128_t)0x8000000000000000 * (__uint128_t)0x1000000000000000 * (__uint128_t)0x10 + (__uint128_t)0x0000000000000000 - 1;
	(void)j;

	ft_printbin(detectchar(   *(__int8_t *)"a", 16, '\0'), 128, 0);
	printf("\n");
	ft_putnbr_base(detectchar(*(__int8_t *)"a", 16, '\0'), 16);
	printf("\n");

	ft_printbin(j, 128, 0);
	printf("\n");
	ft_putnbr_base(j, 10);

	// printf("\n");

	// ft_printbin(42, 8, 0);
	// printf("\n");
	// ft_putnbr_base(42, 10);


	return (0);
}
