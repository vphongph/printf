/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:11:42 by vphongph          #+#    #+#             */
/*   Updated: 2019/07/16 08:12:57 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int64_t		compute_float(long double lf, int64_t precision, __uint128_t *tab128_int, __uint128_t *tab128_dec);

int			main(void)
{
	__uint128_t	tab128_int[BIG_INT_TAB];
	__uint128_t	tab128_dec[BIG_INT_TAB];


	ft_bzero_v2(tab128_int, sizeof(tab128_int));
	ft_bzero_v2(tab128_dec, sizeof(tab128_dec));


	t_lfloat ulf2;(void) ulf2;

	ulf2.y.sign = 0;
	ulf2.y.exponent = 0b000000000000000;
	ulf2.y.mantissa = 0b0000000000000000000000000000000000000000000000000000000000000001;


	// ulf2.y.exponent = 0b111111111111110;
	// ulf2.y.mantissa = 0b1111111111111111111111111111111111111111111111111111111111111111;

	ulf2.x = 298414651.554654654L;

	int precision = 100;
	// int precision = 100;

	printf("%.*Lf\n", precision, ulf2.x);

	int64_t nb_to_print;

	nb_to_print = compute_float(ulf2.x, precision, tab128_int, tab128_dec);

	printf("\nbig int "ALLIANCE"n DEC"RESET" print out : %d\n\n", big_int_n_print(tab128_dec, BIG_INT_TAB, nb_to_print));

	printf("to print %lld\n", nb_to_print);

	printf("\nbig int "ORDER"INT"RESET" print out : %d\n\n", big_int_print(tab128_int, BIG_INT_TAB));


	return (0);
}
