/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_int_add_x_pow_of_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:36:18 by vphongph          #+#    #+#             */
/*   Updated: 2019/04/12 03:18:46 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int8_t			big_int_add(__uint128_t *tab1, __uint128_t *tab2,
	uint16_t tab_s)
{
	int64_t	carry;

	if (!tab1 || !tab2 || tab_s > BIG_INT_TAB)
	{
		ft_putstr_fd_v2(RED"Big int add -> ∅\n"RESET, 2);
		return (-1);
	}
	carry = 0;
	while (tab_s-- > 0)
	{
		tab1[tab_s] += tab2[tab_s];
		tab1[tab_s] += carry;
		if ((carry = (tab1[tab_s] / BIG_INT_CARRY)))
			tab1[tab_s] %= BIG_INT_CARRY;
	}
	return (0);
}

int8_t			big_int_x(__uint128_t *tab_nb, uint16_t tab_size, uint64_t fact)
{
	int64_t	carry;

	if (!tab_nb || tab_size > BIG_INT_TAB || fact > BIG_INT_FACTOR)
	{
		ft_putstr_fd_v2(RED"Big int x -> ∅\n"RESET, 2);
		return (-1);
	}
	carry = 0;
	while (tab_size-- > 0)
	{
		tab_nb[tab_size] *= fact;
		tab_nb[tab_size] += carry;
		if ((carry = (tab_nb[tab_size] / BIG_INT_CARRY)))
			tab_nb[tab_size] %= BIG_INT_CARRY;
	}
	return (0);
}

static int8_t	pow_2_pos(__uint128_t *tab_nb, uint16_t tab_size, int16_t expo)
{
	int16_t	first_run;
	int16_t	second_run;

	first_run = expo / BIG_INT_POW2;
	second_run = expo % BIG_INT_POW2;
	while (first_run--)
		big_int_x(tab_nb, tab_size, BIG_INT_POW2_RES);
	while (second_run--)
		big_int_x(tab_nb, tab_size, 2);
	return ('p');
}

static int8_t	pow_2_neg(__uint128_t *tab_nb, uint16_t tab_size, int16_t expo)
{
	int16_t	first_run;
	int16_t	second_run;

	first_run = -expo / BIG_INT_POW5;
	second_run = -expo % BIG_INT_POW5;
	while (first_run--)
		big_int_x(tab_nb, tab_size, BIG_INT_POW5_RES);
	while (second_run--)
		big_int_x(tab_nb, tab_size, 5);
	return ('n');
}

int8_t			big_int_pow_of_2(__uint128_t *tab, uint16_t tab_s, int16_t expo)
{
	if (!tab || tab_s > BIG_INT_TAB || expo > BIG_INT_EXPO
		|| expo < -BIG_INT_EXPO)
	{
		ft_putstr_fd_v2(RED"Big int pow of 2 -> ∅\n"RESET, 2);
		return (-1);
	}
	ft_bzero_v2(tab, sizeof(__uint128_t) * tab_s);
	tab[tab_s - 1] = 1;
	if (expo < 0)
		return (pow_2_neg(tab, tab_s, expo));
	if (expo > 0)
		return (pow_2_pos(tab, tab_s, expo));
	return ('0');
}
