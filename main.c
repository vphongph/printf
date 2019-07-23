/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:11:42 by vphongph          #+#    #+#             */
/*   Updated: 2019/07/23 05:06:51 by vphongph         ###   ########.fr       */
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
** sf->char_to_print : number of char to print
*/

/*
printable
pseudo inf -> inf + sign
pseudo nan -> nan
inf -> inf + sign (comparable)
nan -> nan
*/

int16_t		lf_check_printable(t_lfloat ulf)
{
	if (ulf.y.mantissa == 0 || !(ulf.y.mantissa ^ 1ULL << 63))
		return ('i');
	return ('n');
}


int16_t		lf_get_check_all(t_printf_float *sf)
{
	t_lfloat ulf;

	if (!sf)
	{
		ft_putstr_fd_v2(RED"Lf get check all -> ∅\n"RESET, 2);
		return (-1);
	}
	ulf.x = sf->value;
	sf->neg = ulf.y.sign;
	sf->exponent = lf_get_exponent(ulf.y.exponent);	
	if (ulf.y.exponent == 0b111111111111111)
		return (lf_check_printable(ulf));
	return (0);
}

int16_t		compute_meta(t_printf_meta *smeta, t_printf_float *sf)
{
	// if (smeta->flags & FT_PRINTF_FLAG_SIGN && smeta->flags & FT_PRINTF_FLAG_SPACE)
		// smeta->flags ^= FT_PRINTF_FLAG_SPACE;

	// if (sf->neg && smeta->flags & FT_PRINTF_FLAG_SPACE)
		// smeta->flags ^= FT_PRINTF_FLAG_SPACE;

	// if (sf->neg && smeta->flags & FT_PRINTF_FLAG_SIGN)
		// smeta->flags ^= FT_PRINTF_FLAG_SIGN;

	// if (smeta->flags & FT_PRINTF_FLAG_LEFT_ADJUST && smeta->flags & FT_PRINTF_FLAG_ZERO_PAD)
		// smeta->flags ^= FT_PRINTF_FLAG_ZERO_PAD;

	// if (i == 'i' || i == 'n')
		// smeta->flags ^= FT_PRINTF_FLAG_ZERO_PAD;
		
	// if (i == 'n')


	// if (sf->neg || smeta->flags & FT_PRINTF_FLAG_SIGN || smeta->flags & FT_PRINTF_FLAG_SPACE)
		// smeta->width--;

	// if (smeta->width > sf->char_to_print)
		// smeta->width -= sf->char_to_print;
	// else
		// smeta->width = 0;
	return (0);
}


int			main(void)
{

	t_printf_float	sf[1];
	t_printf_meta	smeta[1];
	// t_printf_output output[1];(void) output;
	t_lfloat ulf2;(void) ulf2;

	ft_bzero_v2(sf, sizeof(sf));
	ft_bzero_v2(sf, sizeof(smeta));


	ulf2.y.sign = 1;
	ulf2.y.exponent = 0b000000000000000;
	ulf2.y.mantissa = 0b1000000000000000000000000000000000000000000000000000000000000001;

	// printf("expo = %d\n", lf_get_exponent(ulf2.y.exponent));


	// ulf2.x = 003123123210.00010912839018L;
	// ulf2.x = 003123123210.00000000000000;
	// ulf2.x = 00.000;
	// ulf2.x = 2.5000001L;
	// printf("expo = %d\n", lf_get_exponent(ulf2.y.exponent));

	// ulf2.x += 100;

	smeta->precision = 5000;

	sf->value = ulf2.x;

	// printf("%.*La\n", precision, ulf2.x);
	// printf("%.*La\n", precision - 1, ulf2.x);
	// printf("%.*La\n", precision - 2, ulf2.x);

	int i = printf("%#.*LF*\n", smeta->precision, sf->value);
	// int i = printf("%#.*Lf\n", smeta->precision, sf->value);

	if (sf->value == sf->value)
		printf(YELLOW"it's same"RESET"\n");

	// printf("get check all : -%c-", lf_get_check_all(sf));

	// if (lf_get_check_all(sf) == 'i')


	compute_float(smeta, sf);
	// compute_meta(smeta, sf);



	printf("\nbig int "ALLIANCE"n DEC"RESET" print out : %d\n\n", big_int_n_print(sf->tab128_dec, BIG_INT_TAB, sf->digits_to_print));
	// printf("\nbig int "ALLIANCE"n DEC"RESET" print out : %d\n\n", big_int_n_print(sf->tab128_dec, BIG_INT_TAB, smeta->precision));


	// printf("\nbig int "ORDER"INT"RESET" print out : %d\n\n", big_int_print(sf->tab128_int, BIG_INT_TAB));


	printf(" precision %d\n", smeta->precision);
	printf(" mantissa  %lld\n", sf->sm_mantissa);
	printf(" digits    %lld\n", sf->nb_digits);
	printf(" leading 0 %lld\n\n", sf->nb_leading);
	printf(" digits to print    %lld\n", sf->digits_to_print);
	printf(" leading 0 to print %lld\n", sf->leading_to_print);
	printf(" traling 0 to print %lld\n", sf->trailing_to_print);
	printf(" char to print      %lld\n", sf->char_to_print);
	printf("printf return %d\n", i);

	printf("%lu\n", sizeof(sf));
	// printf("%lu\n", sizeof(sf->tab_expo));

	return (0);
}
