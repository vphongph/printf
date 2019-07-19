/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:11:42 by vphongph          #+#    #+#             */
/*   Updated: 2019/07/19 20:45:30 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


/* 
** float_meta
** some useful info from the decimal part of the float
** precision : precision
** sf->sm_mantissa : smallest mantissa (* -1 equal to size of the decimal part)
** sf->nb_digits : number of digits (without leading 0)
** sf->nb_leading : number of leading 0
** sf->digits_to_print : number of digits to print (without leading 0)
** sf->leading_to_print : number of leading 0 to print
** sf->trailing_to_print : number of trailing 0 to print
** sf->char_printed : number of char printed
*/



int16_t		compute_float(long double lf, int32_t precision, t_printf_float *sf);

int			main(void)
{
	t_printf_float sf[1];
	int32_t precision;

	ft_bzero_v2(sf, sizeof(sf));


	t_lfloat ulf2;(void) ulf2;

	ulf2.y.sign = 0;
	ulf2.y.exponent = 0b000000000000000;
	ulf2.y.mantissa = 0b1111111111111111111111111111111111111111111111111111111111111111;

	printf("expo = %d\n", lf_get_exponent(ulf2.y.exponent));


	// ulf2.x = 003123123210.00010912839018;
	// ulf2.x = 003123123210.00000000000000;
	// ulf2.x = 00.000;
	ulf2.x = 2.5000001L;
	printf("expo = %d\n", lf_get_exponent(ulf2.y.exponent));

	// ulf2.x += 1;


	precision = 100;

	printf("%.*Le\n", precision, ulf2.x);
	printf("%.*Lf\n", precision, ulf2.x);


	compute_float(ulf2.x, precision, sf);

	// printf("\nbig int "ALLIANCE"n DEC"RESET" print out : %d\n\n", big_int_n_print(sf->tab128_dec, BIG_INT_TAB, sf->digits_to_print));
	// printf("\nbig int "ALLIANCE"n DEC"RESET" print out : %d\n\n", big_int_n_print(sf->tab128_dec, BIG_INT_TAB, precision));


	// printf("\nbig int "ORDER"INT"RESET" print out : %d\n\n", big_int_print(sf->tab128_int, BIG_INT_TAB));


	printf(" precision %d\n", precision);
	printf(" mantissa  %lld\n", sf->sm_mantissa);
	printf(" digits    %lld\n", sf->nb_digits);
	printf(" leading 0 %lld\n\n", sf->nb_leading);
	printf(" digits to print    %lld\n", sf->digits_to_print);
	printf(" leading 0 to print %lld\n", sf->leading_to_print);
	printf(" traling 0 to print %lld\n", sf->trailing_to_print);
	printf(" char printed       %lld\n", sf->char_printed);




	return (0);
}
