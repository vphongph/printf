/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lf_get_mantissa_pow.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:52:10 by vphongph          #+#    #+#             */
/*   Updated: 2019/04/10 13:49:47 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Never return--*tab_expo
*/

static int	clean_tab_expo(int16_t *tab_expo)
{
	int16_t i;

	i = 0;
	while ((uint16_t)i < (sizeof(int16_t) * MANTISSA_TAB / sizeof(__uint128_t)))
		((__uint128_t *)tab_expo)[i++] = (BIG_INT_EXPO + 1) * DISTRIB_2_TO_8;
	i *= sizeof(__uint128_t) / sizeof(int16_t);
	while (i <= MANTISSA_TAB)
		tab_expo[i++] = BIG_INT_EXPO + 1;
	return (i);
}

int16_t		lf_get_mantissa_pow(int16_t *tab_expo, long double lf)
{
	t_longf		ulf;
	int16_t		shift;
	int16_t		expo;
	__uint128_t	one;
	int16_t		i;

	ulf.x = lf;
	i = 0;
	if (!tab_expo && (ft_putstr_v2(RED"lf get mantissa pow -> ∅\n"RESET)))
		return (-1);
	(expo = lf_get_exponent(ulf.y.exponent)) == -EXP_LF ? expo++ : expo;
	clean_tab_expo(tab_expo);
	one = 1;
	shift = MANTISSA_TAB - 1;
	while (shift >= 0)
	{
		if (ulf.y.mantissa & one << shift)
			tab_expo[i++] = shift - (MANTISSA_TAB - 1) + expo;
		shift--;
	}
	return (i == 0 ? 0 : -tab_expo[i - 1]);
}
