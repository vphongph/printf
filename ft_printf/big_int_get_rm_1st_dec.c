/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_int_get_rm_1st_dec.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 01:36:41 by vphongph          #+#    #+#             */
/*   Updated: 2019/07/25 01:22:57 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int16_t		big_int_get_1st_dec(__uint128_t *tab_nb, int16_t tab_size)
{
	int16_t		i;
	__uint128_t carry;

	i = 0;
	carry = BIG_INT_CARRY / 10;
	if (!tab_nb || tab_size > BIG_INT_TAB)
	{
		ft_putstr_fd_v2(RED"Big int get 1st dec -> ∅\n"RESET, 2);
		return (-1);
	}
	while (i < tab_size && !tab_nb[i])
		i++;
	while (carry)
	{
		if (tab_nb[i] / carry)
			return (tab_nb[i] / carry);
		carry /= 10;
	}
	return (0);
}


int16_t		big_int_rm_1st_dec(__uint128_t *tab_nb, int16_t tab_size)
{
	int16_t		i;
	__uint128_t carry;

	i = 0;
	carry = BIG_INT_CARRY / 10;
	if (!tab_nb || tab_size > BIG_INT_TAB)
	{
		ft_putstr_fd_v2(RED"Big int rm 1st dec -> ∅\n"RESET, 2);
		return (-1);
	}
	while (i < tab_size && !tab_nb[i])
		i++;
	while (carry)
	{
		if (tab_nb[i] / carry)
		{
			tab_nb[i] %= carry;
			return (1);
		}
		carry /= 10;
	}
	return (0);
}
