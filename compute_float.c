/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 02:47:42 by vphongph          #+#    #+#             */
/*   Updated: 2019/07/16 08:13:27 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Why location = precision + smallest_expo + nb_digit + 1 ?
** Because the original format non factored is :
** (precision + 1) - (-smallest_expo - nb_digit)
** Same reasoningfor the return exept +1
** because we return the number of dec to print (without leading 0)
*/

static int16_t	round(__uint128_t *tab128_int, __uint128_t *tab128_dec,
	int64_t location, int16_t smallest_expo)
{
	int16_t nb_digit;

	big_int_round(tab128_dec, location);
	if ((nb_digit = big_int_count(tab128_dec, BIG_INT_TAB)) > -smallest_expo)
	{
		big_int_rm_1st_dec(tab128_dec, BIG_INT_TAB);
		big_int_add_one(tab128_int, BIG_INT_TAB - 1, 1);
		--nb_digit;
	}
	return (nb_digit);
}

int64_t			compute_float(long double lf, int64_t precision,
	__uint128_t *tab128_int, __uint128_t *tab128_dec)
{
	int16_t nb_digit;
	int16_t smallest_expo;
	int64_t location;
	int16_t	tab_expo[MANTISSA_TAB + 1];

	nb_digit = 0;
	smallest_expo = lf_get_mantissa_pow(tab_expo, lf);
	big_int_calc_int(tab128_int, BIG_INT_TAB, tab_expo);
	if (smallest_expo < 0 && precision >= 0)
	{
		big_int_calc_dec(tab128_dec, BIG_INT_TAB, tab_expo);
		nb_digit = big_int_count(tab128_dec, BIG_INT_TAB);
		location = precision + smallest_expo + nb_digit + 1;
		if (precision < -smallest_expo && location > 0)
		{
			nb_digit = round(tab128_int, tab128_dec, location, smallest_expo);
			// big_int_round(tab128_dec, location);
			// if ((nb_digit = big_int_count(tab128_dec, BIG_INT_TAB)) > -smallest_expo)
			// {
				// big_int_rm_1st_dec(tab128_dec, BIG_INT_TAB);
				// big_int_add_one(tab128_int, BIG_INT_TAB - 1, 1);
				// --nb_digit;
			// }
		}
	}
	return (nb_digit ? precision + smallest_expo + nb_digit : 0);
}

/*
** TO BE REMOVED
** Is it necessary to return the number of leading or trailing 0 ?
*/
