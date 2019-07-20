/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:11:42 by vphongph          #+#    #+#             */
/*   Updated: 2019/07/20 05:42:14 by vphongph         ###   ########.fr       */
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




int			main(void)
{

	t_printf_float	sf[1];
	t_printf_meta	smeta[1];
	t_printf_output output[1];(void) output;
	t_lfloat ulf2;(void) ulf2;

	ft_bzero_v2(sf, sizeof(sf));


	ulf2.y.sign = 0;
	ulf2.y.exponent = 0b000000000000000;
	ulf2.y.mantissa = 0b1111111111111111111111111111111111111111111111111111111111111111;

	// printf("expo = %d\n", lf_get_exponent(ulf2.y.exponent));


	// ulf2.x = 003123123210.00010912839018L;
	// ulf2.x = 003123123210.00000000000000;
	// ulf2.x = 00.000;
	// ulf2.x = 2.5000001L;
	// printf("expo = %d\n", lf_get_exponent(ulf2.y.exponent));

	// ulf2.x += 1;

	sf->value = ulf2.x;

	smeta->precision = 16445;

	// printf("%.*La\n", precision, ulf2.x);
	// printf("%.*La\n", precision - 1, ulf2.x);
	// printf("%.*La\n", precision - 2, ulf2.x);

	// int i = printf("%000000 150.*Lf\n", smeta->precision, sf->value);
	int i = printf("%.*Lf\n", smeta->precision, sf->value);


	check_space_
	compute_float(smeta, sf);


	printf("\nbig int "ALLIANCE"n DEC"RESET" print out : %d\n\n", big_int_n_print(sf->tab128_dec, BIG_INT_TAB, sf->digits_to_print));
	// printf("\nbig int "ALLIANCE"n DEC"RESET" print out : %d\n\n", big_int_n_print(sf->tab128_dec, BIG_INT_TAB, smeta->precision));


	printf("\nbig int "ORDER"INT"RESET" print out : %d\n\n", big_int_print(sf->tab128_int, BIG_INT_TAB));


	printf(" precision %d\n", smeta->precision);
	printf(" mantissa  %lld\n", sf->sm_mantissa);
	printf(" digits    %lld\n", sf->nb_digits);
	printf(" leading 0 %lld\n\n", sf->nb_leading);
	printf(" digits to print    %lld\n", sf->digits_to_print);
	printf(" leading 0 to print %lld\n", sf->leading_to_print);
	printf(" traling 0 to print %lld\n", sf->trailing_to_print);
	printf(" char printed       %lld\n", sf->char_printed);


	printf("%d\n", i);
	printf("%lu\n", sizeof(sf));

	return (0);
}
