/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:11:42 by vphongph          #+#    #+#             */
/*   Updated: 2019/07/17 07:01:27 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


/* 
** float_meta
** some useful info from the decimal part of the float
** fmeta->precision : precision
** fmeta->sm_mantissa : smallest mantissa (* -1 equal to size of the decimal part)
** fmeta->nb_digits : number of digits (without leading 0)
** fmeta->nb_leading : number of leading 0
** fmeta->digits_to_print : number of digits to print (without leading 0)
** fmeta->leading_to_print : number of leading 0 to print
** fmeta->trailing_to_print : number of trailing 0 to print
** fmeta->char_printed : number of char printed
*/



int16_t		compute_float(long double lf, t_float_meta *fmeta,
	__uint128_t *tab128_int, __uint128_t *tab128_dec);

int			main(void)
{
	__uint128_t	tab128_int[BIG_INT_TAB];
	__uint128_t	tab128_dec[BIG_INT_TAB];
	t_float_meta fmeta[1];




	ft_bzero_v2(tab128_int, sizeof(tab128_int));
	ft_bzero_v2(tab128_dec, sizeof(tab128_dec));
	ft_bzero_v2(fmeta, sizeof(fmeta));


	t_lfloat ulf2;(void) ulf2;

	ulf2.y.sign = 0;
	ulf2.y.exponent = 0b000000000000000;
	ulf2.y.mantissa = 0b0000000000000000000000000000000000000000000000000000000000000001;


	// ulf2.y.exponent = 0b111111111111110;
	// ulf2.y.mantissa = 0b1111111111111111111111111111111111111111111111111111111111111111;

	ulf2.x = 9812723987.09283490720000234023043L;

	fmeta->precision = 20;

	printf("%.*Lf\n", (int)fmeta->precision, ulf2.x);

	compute_float(ulf2.x, fmeta, tab128_int, tab128_dec);

	printf("\nbig int "ALLIANCE"n DEC"RESET" print out : %d\n\n", big_int_n_print(tab128_dec, BIG_INT_TAB, fmeta->digits_to_print));


	printf("\nbig int "ORDER"INT"RESET" print out : %d\n\n", big_int_print(tab128_int, BIG_INT_TAB));


	if (fmeta->digits_to_print >= 0)
		fmeta->leading_to_print = fmeta->nb_leading;
	else
		fmeta->leading_to_print = fmeta->precision;

	if (fmeta->digits_to_print > fmeta->nb_digits)
		fmeta->trailing_to_print = fmeta->digits_to_print - fmeta->nb_digits;

	if (fmeta->digits_to_print < 0 || fmeta->nb_digits == 0)
		fmeta->digits_to_print = 0;

	if (!(fmeta->char_printed = big_int_count(tab128_int, BIG_INT_TAB)))
		fmeta->char_printed = 1;

	if (fmeta->precision > 0)
		fmeta->char_printed += fmeta->leading_to_print + fmeta->digits_to_print + fmeta->trailing_to_print + 1;


	printf(" precision %lld\n", fmeta->precision);
	printf(" mantissa  %lld\n", fmeta->sm_mantissa);
	printf(" digits    %lld\n", fmeta->nb_digits);
	printf(" leading 0 %lld\n\n", fmeta->nb_leading);
	printf(" digits to print    %lld\n", fmeta->digits_to_print);
	printf(" leading 0 to print %lld\n", fmeta->leading_to_print);
	printf(" traling 0 to print %lld\n", fmeta->trailing_to_print);
	printf(" char printed       %lld\n", fmeta->char_printed);

	return (0);
}
