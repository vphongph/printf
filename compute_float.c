/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 02:47:42 by vphongph          #+#    #+#             */
/*   Updated: 2019/07/18 06:20:53 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Why location = precision + smallest_expo + nb_digit + 1 ?
** OR location
** = fmeta->precision + fmeta->sm_mantissa + fmeta->nb_digits + 1 ?
** Because the original format non factored is :
** (precision + 1) - (-smallest_expo - nb_digit)
** Same reasoning for the return exept +1
** because we return the number of dec to print (without leading 0)
*/

int16_t		compute_float(long double lf, t_float_meta *fmeta,
	__uint128_t *tab128_int, __uint128_t *tab128_dec)
{
	int64_t location;
	int16_t	tab_expo[MANTISSA_TAB + 1];

	fmeta->sm_mantissa = lf_get_mantissa_pow(tab_expo, lf);
	big_int_calc_int(tab128_int, BIG_INT_TAB, tab_expo);
	if (fmeta->sm_mantissa >= 0 || fmeta->precision == 0)
		return (0);
	big_int_calc_dec(tab128_dec, BIG_INT_TAB, tab_expo);
	fmeta->nb_digits = big_int_count(tab128_dec, BIG_INT_TAB);
	location = fmeta->precision + fmeta->sm_mantissa + fmeta->nb_digits + 1;
	if (location <= fmeta->nb_digits && location > 0)
	{
		big_int_round(tab128_dec, location);
		if ((fmeta->nb_digits = big_int_count(tab128_dec, BIG_INT_TAB))
			> -fmeta->sm_mantissa)
		{
			big_int_rm_1st_dec(tab128_dec, BIG_INT_TAB);
			big_int_add_one(tab128_int, BIG_INT_TAB - 1, 1);
			--fmeta->nb_digits;
		}
	}
	fmeta->nb_leading = -(fmeta->sm_mantissa + fmeta->nb_digits);
	fmeta->digits_to_print = fmeta->precision - fmeta->nb_leading;
	return (1);
}
