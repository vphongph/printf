/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_int_round.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 05:59:48 by vphongph          #+#    #+#             */
/*   Updated: 2019/06/30 08:20:45 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static int16_t	check_trailing(__uint128_t *tab_nb, int16_t index, __uint128_t one)
{
	if (tab_nb[index] % one)
		return (1);
	while (++index < BIG_INT_TAB)
		if (tab_nb[index])
			return (1);
	return (0);
}

static int16_t	check_round(__uint128_t *tab_nb, int16_t index, __uint128_t one)
{
	__uint128_t to_round;
	int16_t trailing;

	to_round = tab_nb[index] / one % 10;

	if (to_round > 5)
		big_int_add_one(tab_nb, index, one * 10);
	if (to_round == 5)
	{
		trailing = check_trailing(tab_nb, index, one);
		if (one < BIG_INT_CARRY / 10)
			if (tab_nb[index] / (one * 10) % 2 || trailing)
				big_int_add_one(tab_nb, index, one * 10);
		if (one == BIG_INT_CARRY / 10)
			if (index > 0 && (tab_nb[--index] % 2 || trailing))
				big_int_add_one(tab_nb, index, 1);
	}
	return (0);
}

static int		jump(int *i, int *current, int location)
{
	int tmp_i = *i;
	int tmp_current = *current - 1;
	*i += (location - tmp_current) / BIG_INT_DIGIT;
	if ((location - tmp_current) % BIG_INT_DIGIT)
		*i += 1;
	*current +=  BIG_INT_DIGIT * (*i - (tmp_i + 1));
	if (*i < BIG_INT_TAB)
		return (*current);
	return (-1);
}

int16_t	big_int_round(__uint128_t *tab_nb, uint16_t tab_size, int16_t location)
{
	int i;
	int current;
	__uint128_t carry;
	
	i = 0;
	current = 1;
	carry = BIG_INT_CARRY / 10;

	while (i < tab_size && !tab_nb[i])
		i++;
	while (i < tab_size && !(tab_nb[i] / carry))
		carry /= 10;
	while (i < tab_size && carry)
	{
		if (current == location)
			return (check_round(tab_nb, i, carry));
		current++;
		carry /= 10;
	}
	carry = BIG_INT_CARRY / 10;
	if ((jump(&i, &current, location)) < 0)
		carry = 0;
	while (carry)
	{
		if (current == location)
			return (check_round(tab_nb, i, carry));
		current++;
		carry /= 10;
	}
	return (0);
}