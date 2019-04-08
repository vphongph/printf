/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lf_get_mantissa_pow.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:52:10 by vphongph          #+#    #+#             */
/*   Updated: 2019/04/08 22:27:10 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	clean_tab_expo(int16_t *tab_expo)
{
	int16_t i;

	i = 0;
	while ((uint16_t)i < (sizeof(int16_t) * MANTISSA_TAB / sizeof(__uint128_t)))
		((__uint128_t *)tab_expo)[i++] = (BIG_INT_EXPO + 1) * DISTRIB_INT128_INT16;
	i *= sizeof(__uint128_t) / sizeof(int16_t);
	while (i <= MANTISSA_TAB)
		tab_expo[i++] = BIG_INT_EXPO + 1;
	return (i);
}

int			lf_get_mantissa_pow(int16_t *tab_expo, long double lf)
{
	int16_t i;
	int16_t j;
	int16_t expo;
	__uint128_t one;
	t_longf ulf;

	if (!tab_expo)
	{
		ft_putstr_v2(RED"lf get mantissa pow -> ∅\n"RESET);
		return (-1);
	}
	if ((expo = lf_get_exponent(ulf.y.exponent)) == -EXP_LF)
		expo++;
	clean_tab_expo(tab_expo);
	i = 0;
	one = 1;
	j = MANTISSA_TAB - 1;
	while (j >= 0)
	{
		if (ulf.y.mantissa & one << j)
		tab_expo[i++] = j - (MANTISSA_TAB - 1) + expo;
		j--;
	}
	return (0);
}
