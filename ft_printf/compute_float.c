/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 02:47:42 by vphongph          #+#    #+#             */
/*   Updated: 2019/07/25 01:47:08 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Why sf->location = smeta->precision + smallest_expo + nb_digit + 1 ?
** OR sf->location
** = smeta->precision + sf->sm_mantissa + sf->nb_digits_dec + 1 ?
** Because the original format non factored is :
** (smeta->precision + 1) - (-smallest_expo - nb_digit)
** Same reasoning for the return exept +1
** because we return the number of dec to print (without leading 0)
*/

int16_t		check_round_int(t_printf_float *sf)
{
	if ((sf->nb_digits_dec = big_int_count(sf->tab128_dec, BIG_INT_TAB))
		> -sf->sm_mantissa)
		return (1);
	if (sf->nb_leading == 0
		&& big_int_get_1st_dec(sf->tab128_dec, BIG_INT_TAB) == 5
		&& sf->tab128_int[BIG_INT_TAB - 1] % 2)
		return (1);
	return (0);
}

int16_t		compute_to_print(t_printf_meta *smeta, t_printf_float *sf,
	int16_t i)
{
	if (i == 0)
		sf->trailing_to_print = smeta->precision;
	if (i == 1)
	{
		sf->nb_leading = -(sf->sm_mantissa + sf->nb_digits_dec);
		sf->digits_to_print = smeta->precision - sf->nb_leading;
	}
	if (sf->digits_to_print >= 0)
		sf->leading_to_print = sf->nb_leading;
	else
		sf->leading_to_print = smeta->precision;
	if (sf->digits_to_print > sf->nb_digits_dec)
	{
		sf->trailing_to_print = sf->digits_to_print - sf->nb_digits_dec;
		sf->digits_to_print = sf->nb_digits_dec;
	}
	if (sf->digits_to_print < 0)
		sf->digits_to_print = 0;
	if (!(sf->nb_digits_int = big_int_count(sf->tab128_int, BIG_INT_TAB)))
		sf->nb_digits_int = 1;
	sf->char_to_print = sf->nb_digits_int + sf->leading_to_print
		+ sf->digits_to_print + sf->trailing_to_print + 1;
	return (i);
}

int16_t		compute_float(t_printf_meta *smeta, t_printf_float *sf)
{
	int16_t	tab_expo[MANTISSA_TAB + 1];

	sf->sm_mantissa = lf_get_mantissa_pow(tab_expo, sf->value);
	big_int_calc_int(sf->tab128_int, BIG_INT_TAB, tab_expo);
	if (sf->sm_mantissa >= 0)
		return (compute_to_print(smeta, sf, 0));
	big_int_calc_dec(sf->tab128_dec, BIG_INT_TAB, tab_expo);
	sf->nb_digits_dec = big_int_count(sf->tab128_dec, BIG_INT_TAB);
	sf->location = smeta->precision + sf->sm_mantissa + sf->nb_digits_dec + 1;
	if (sf->location <= sf->nb_digits_dec && sf->location > 0)
	{
		big_int_round(sf->tab128_dec, sf->location);
		if (check_round_int(sf))
		{
			big_int_rm_1st_dec(sf->tab128_dec, BIG_INT_TAB);
			big_int_add_one(sf->tab128_int, BIG_INT_TAB - 1, 1);
			--sf->nb_digits_dec;
		}
	}
	return (compute_to_print(smeta, sf, 1));
}
