/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_int_print_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:41:21 by vphongph          #+#    #+#             */
/*   Updated: 2019/05/30 20:36:02 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int16_t	print_tab(__uint128_t *tab, int16_t tab_s, int16_t i, int16_t j)
{
	__uint128_t carry;

	carry = BIG_INT_CARRY;
	while (i < tab_s)
	{
		while (tab[i] && tab[i] < carry / 10)
		{
			write(1, "0", 1);
			carry /= 10;
			j++;
		}
		carry = BIG_INT_CARRY;
		if (tab[i])
			j += ft_putnbr_base(tab[i], 10, 0);
		if (!tab[i])
		{
			write(1, "0000000000000000000000000000000000000", BIG_INT_DIGIT);
			j += BIG_INT_DIGIT;
		}
		i++;
	}
	if (j == 0 && write(1, "0", 1))
		return (1);
	return (j);
}

int16_t			big_int_print(__uint128_t *tab_nb, uint16_t tab_size)
{
	int16_t i;
	int16_t j;

	if (!tab_nb || tab_size > BIG_INT_TAB)
	{
		ft_putstr_fd_v2(RED"Big int print -> ∅\n"RESET, 2);
		return (-1);
	}
	i = 0;
	j = 0;
	while (i < tab_size && !(tab_nb[i]))
		i++;
	if (i < tab_size && tab_nb[i])
		j += ft_putnbr_base(tab_nb[i++], 10, 0);
	return (print_tab(tab_nb, tab_size, i, j));
}

int16_t			big_int_count(__uint128_t *tab_nb, uint16_t tab_size)
{
	int16_t		i;
	int16_t		digit;
	__uint128_t	nb;

	if (!tab_nb || tab_size > BIG_INT_TAB)
	{
		ft_putstr_fd_v2(RED"Big int count -> ∅\n"RESET, 2);
		return (0);
	}
	i = 0;
	digit = 0;
	while (i < tab_size && !tab_nb[i])
		i++;
	if (i < tab_size)
		nb = tab_nb[i];
	while (i < tab_size && nb / 10)
	{
		nb /= 10;
		digit++;
	}
	if (i < tab_size && nb / 1)
		digit++;
	if (i < tab_size)
		digit += BIG_INT_DIGIT * (tab_size - (i + 1));
	return (digit);
}
