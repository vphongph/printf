/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_int_calc_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:15:07 by vphongph          #+#    #+#             */
/*   Updated: 2019/04/12 19:18:23 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int16_t	check(__uint128_t *tab_nb, uint16_t tab_s, int16_t *tab_expo)
{
	int16_t	i;

	i = 0;
	if (!tab_nb || tab_s > BIG_INT_TAB || !tab_expo)
	{
		ft_putstr_fd_v2(RED"Big int calc int -> ∅\n"RESET, 2);
		return (-2);
	}
	while (tab_expo[i] != BIG_INT_EXPO + 1 && tab_expo[i] >= 0
		&& i < MANTISSA_TAB)
		i++;
	if (!i)
		return (-1);
	return (i);
}

int8_t			big_int_calc_int(__uint128_t *tab_nb, uint16_t tab_s,
	int16_t *tab_expo)
{
	int16_t		i;
	int16_t		diff_expo;
	__uint128_t	tab_nb_tmp[BIG_INT_TAB];

	if ((i = check(tab_nb, tab_s, tab_expo)) < 0)
		return (i);
	diff_expo = tab_expo[i - 1];
	big_int_pow_of_2(tab_nb_tmp, tab_s, tab_expo[i - 1]);
	big_int_add(tab_nb, tab_nb_tmp, tab_s);
	i -= 2;
	while (i >= 0)
	{
		while (tab_expo[i] - diff_expo)
		{
			big_int_x(tab_nb_tmp, tab_s, 2);
			diff_expo++;
		}
		big_int_add(tab_nb, tab_nb_tmp, tab_s);
		i--;
	}
	return (0);
}
