/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_int_n_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:41:21 by vphongph          #+#    #+#             */
/*   Updated: 2019/05/30 21:59:47 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

/*
** ATTENTION paramètre n (int16),
** la fonction appelle putnnbr_base avec n (int8),
** ATTENTION à over/underflow de ce dernier.
*/

static int16_t	print_last_tab(__uint128_t *tab_nb, uint16_t tab_s, int16_t n,
	int16_t *i)
{
	__uint128_t carry;

	carry = BIG_INT_CARRY / 10;
	if (*i < tab_s)
	{
		while (tab_nb[*i] && tab_nb[*i] < carry && n > 0)
		{
			write(1, "0", 1);
			carry /= 10;
			n--;
		}
		if (tab_nb[*i])
			ft_putnnbr_base(tab_nb[*i], 10, 0, n);
		if (!tab_nb[*i])
			write(1, "0000000000000000000000000000000000000", n);
	}
	return (n);
}

static int16_t	print_full_tab(__uint128_t *tab_nb, uint16_t tab_s, int16_t n,
	int16_t *i)
{
	__uint128_t carry;

	carry = BIG_INT_CARRY / 10;
	while (*i < tab_s && n >= BIG_INT_DIGIT)
	{
		while (tab_nb[*i] && tab_nb[*i] < carry)
		{
			write(1, "0", 1);
			carry /= 10;
		}
		carry = BIG_INT_CARRY / 10;
		if (tab_nb[*i])
			ft_putnbr_base(tab_nb[*i], 10, 0);
		if (!tab_nb[*i])
			write(1, "0000000000000000000000000000000000000", BIG_INT_DIGIT);
		(*i)++;
		n -= BIG_INT_DIGIT;
	}
	return (n);
}

static int16_t	print_1st_tab(__uint128_t *tab_nb, uint16_t tab_s, int16_t n,
	int16_t i)
{
	int16_t		tmp_n;
	__uint128_t	one;

	tmp_n = n;
	one = 1;
	while (i < tab_s && tab_nb[i] / one)
	{
		n--;
		one *= 10;
	}
	if (n < 0)
	{
		ft_putnnbr_base(tab_nb[i], 10, 0, tmp_n);
		return (0);
	}
	ft_putnbr_base(tab_nb[i], 10, 0);
	return (n);
}

static int16_t	check_param(__uint128_t *tab_nb, uint16_t tab_s, int16_t n,
	int16_t i)
{
	if (!tab_nb || tab_s > BIG_INT_TAB)
	{
		ft_putstr_fd_v2(RED"Big int print -> ∅\n"RESET, 2);
		return (-2);
	}
	while (i < tab_s && !(tab_nb[i]))
		i++;
	if (i == tab_s || n < 0)
	{
		write(1, "0", 1);
		return (-1);
	}
	return (i);
}

int16_t			big_int_n_print(__uint128_t *tab_nb, uint16_t tab_s, int16_t n)
{
	int16_t i;

	i = 0;
	if ((i = check_param(tab_nb, tab_s, n, i)) < 0)
		return (i);
	if ((n = print_1st_tab(tab_nb, tab_s, n, i)) == 0 || ++i == tab_s)
		return (0);
	if ((n = print_full_tab(tab_nb, tab_s, n, &i)) == 0)
		return (1);
	print_last_tab(tab_nb, tab_s, n, &i);
	return (2);
}
