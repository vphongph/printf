/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_int_n_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:41:21 by vphongph          #+#    #+#             */
/*   Updated: 2019/04/19 02:39:50 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

static int16_t	print_tab(__uint128_t *tab, int16_t tab_s, int16_t i, int16_t n)
{
	__uint128_t carry;

	carry = BIG_INT_CARRY / 10;
	while (i < tab_s && n >= 32)
	{
		while (tab[i] && tab[i] < carry)
		{
			write(1, "0", 1);
			carry /= 10;
		}
		carry = BIG_INT_CARRY / 10;
		if (tab[i])
			ft_putnbr_base(tab[i], 10, 0);
		if (!tab[i])
			write(1, "0000000000000000000000000000000000000", BIG_INT_DIGIT);
		i++;
		n -= 32;
	}
	if (i < tab_s && n > 0)
	{
		while (tab[i] && tab[i] < carry && n > 0)
		{
			write(1, "0", 1);
			carry /= 10;
			n--;
		}
		carry = BIG_INT_CARRY / 10;
		if (tab[i])
			ft_putnnbr_base(tab[i], 10, 0, n);
		if (!tab[i])
			write(1, "0000000000000000000000000000000000000", n);
	}
	return (n);
}

int16_t			big_int_n_print(__uint128_t *tab_nb, uint16_t tab_s, int16_t n)
{
	int16_t i;
	int16_t tmp_n;
	__uint128_t one;

	if (!tab_nb || tab_s > BIG_INT_TAB)
	{
		ft_putstr_fd_v2(RED"Big int print -> ∅\n"RESET, 2);
		return (-1);
	}
	i = 0;
	tmp_n = n;
	one = 1;
	while (i < tab_s && !(tab_nb[i]))
		i++;
	if (i == tab_s)
		write (1, "0", 1);
	while (i < tab_s && tab_nb[i] / one)
	{
		n--;
		one *= 10;
	}
	if (n <= 0)
		return (ft_putnnbr_base(tab_nb[i], 10, 0, tmp_n));
	if (i < tab_s)
		ft_putnbr_base(tab_nb[i++], 10, 0);
	return (print_tab(tab_nb, tab_s, i, n));
}
