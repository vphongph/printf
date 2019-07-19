/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 02:47:42 by vphongph          #+#    #+#             */
/*   Updated: 2019/07/19 05:34:08 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Why sf->location = precision + smallest_expo + nb_digit + 1 ?
** OR sf->location
** = precision + sf->sm_mantissa + sf->nb_digits + 1 ?
** Because the original format non factored is :
** (precision + 1) - (-smallest_expo - nb_digit)
** Same reasoning for the return exept +1
** because we return the number of dec to print (without leading 0)
*/

int16_t		compute_meta(t_printf_float *sf, int64_t precision, int16_t i)
{
	if (i == 0)
		sf->trailing_to_print = precision;
	if (i == 1)
	{
		sf->nb_leading = -(sf->sm_mantissa + sf->nb_digits);
		sf->digits_to_print = precision - sf->nb_leading;
	}
	if (sf->digits_to_print >= 0)
		sf->leading_to_print = sf->nb_leading;
	else
		sf->leading_to_print = precision;
	if (sf->digits_to_print > sf->nb_digits)
	{
		sf->trailing_to_print = sf->digits_to_print - sf->nb_digits;
		sf->digits_to_print = sf->nb_digits;
	}
	if (sf->digits_to_print < 0)
		sf->digits_to_print = 0;
	if (!(sf->char_printed = big_int_count(sf->tab128_int, BIG_INT_TAB)))
		sf->char_printed = 1;
	if (precision > 0)
		sf->char_printed += sf->leading_to_print
		+ sf->digits_to_print + sf->trailing_to_print + 1;
	return (i);
}

int16_t		compute_float(long double lf, int64_t precision, t_printf_float *sf)
{
	int16_t	tab_expo[MANTISSA_TAB + 1];

	sf->sm_mantissa = lf_get_mantissa_pow(tab_expo, lf);
	big_int_calc_int(sf->tab128_int, BIG_INT_TAB, tab_expo);
	if (sf->sm_mantissa >= 0 || precision == 0)
		return (compute_meta(sf, precision, 0));
	big_int_calc_dec(sf->tab128_dec, BIG_INT_TAB, tab_expo);
	sf->nb_digits = big_int_count(sf->tab128_dec, BIG_INT_TAB);
	sf->location = precision + sf->sm_mantissa + sf->nb_digits + 1;
	if (sf->location <= sf->nb_digits && sf->location > 0)
	{
		big_int_round(sf->tab128_dec, sf->location);
		if ((sf->nb_digits = big_int_count(sf->tab128_dec, BIG_INT_TAB))
			> -sf->sm_mantissa)
		{
			big_int_rm_1st_dec(sf->tab128_dec, BIG_INT_TAB);
			big_int_add_one(sf->tab128_int, BIG_INT_TAB - 1, 1);
			--sf->nb_digits;
		}
	}
	return (compute_meta(sf, precision, 1));
}
