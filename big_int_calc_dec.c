/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_int_calc_dec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:15:07 by vphongph          #+#    #+#             */
/*   Updated: 2019/04/10 01:50:02 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


static int16_t	check(__uint128_t *tab_nb, uint16_t tab_s, int16_t *tab_expo)
{
	int16_t	i;

	i = 0;
	if (!tab_nb || tab_s > BIG_INT_TAB || !tab_expo)
	{
		ft_putstr_fd_v2(RED"Big int calc dec -> ∅\n"RESET, 2);
		return (-2);
	}
	while (tab_expo[i] != BIG_INT_EXPO + 1 && tab_expo[i] >= 0)
		i++;
	if (tab_expo[i] == BIG_INT_EXPO + 1)
		return (-1);
	return (i);
}

int8_t			big_int_calc_dec(__uint128_t *tab_nb, uint16_t tab_s,
	int16_t *tab_expo)
{
	int16_t		i;
	int16_t		diff_expo;
	__uint128_t	tab_nb_tmp[BIG_INT_TAB];

	if ((i = check(tab_nb, tab_s, tab_expo)) < 0)
		return (i);
	diff_expo = -tab_expo[i];
	big_int_pow_of_2(tab_nb_tmp, tab_s, tab_expo[i]);
	big_int_add(tab_nb, tab_nb_tmp, tab_s);
	i += 1;
	while (tab_expo[i] != BIG_INT_EXPO + 1)
	{
		while (-tab_expo[i] - diff_expo)
		{
			big_int_x(tab_nb_tmp, tab_s, 5);
			big_int_x(tab_nb, tab_s, 10);
			diff_expo++;
		}
		big_int_add(tab_nb, tab_nb_tmp, tab_s);
		i++;
	}
	return (0);
}
