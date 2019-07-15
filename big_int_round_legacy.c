/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_int_round_legacy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 05:59:48 by vphongph          #+#    #+#             */
/*   Updated: 2019/06/30 07:25:44 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

/* Big int round from test big int.
** First functional big int round,
** with all debug stuff
*/

static void		lol_write_space(int z)
{
	(void)z;
	write(1,"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			"                                                                                                                                                                                                        "
			, z);
}

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
		// trailing = 0;
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
	{
		printf(YELLOW"OK JUMP"RESET"\n");
		return (*current);
	}
	return (-1);
}

int16_t			big_int_round_legacy(__uint128_t *tab_nb, uint16_t tab_size, int16_t location)
{
	int i;
	int current;
	__uint128_t carry;
	i = 0;

	int z = -1;

	current = 1;
	carry = BIG_INT_CARRY / 10;

	while (i < tab_size && !tab_nb[i])
		i++;
	while (i < tab_size && !(tab_nb[i] / carry))
		carry /= 10;
	while (i < tab_size && carry)
	{
		z++;
		if (current == location)
		{
			lol_write_space(z);
			ft_putnbr_base(carry, 10, 10);
			printf("\n");
			return (check_round(tab_nb, i, carry));
		}
		current++;
		carry /= 10;
	}
	printf("I first : %d\n", i);
	printf("current first : %d\n", current);
	carry = BIG_INT_CARRY / 10;
	if ((z = jump(&i, &current, location)) < 0)
		carry = 0;
	z -= 2;
	printf("I : %d\n", i);
	printf("current : %d\n", current);
	while (carry)
	{
		z++;
		if (current == location)
		{
			lol_write_space(z);
			ft_putnbr_base(carry, 10, 10);
			printf("\n");
			return (check_round(tab_nb, i, carry));
		}
		current++;
		carry /= 10;
	}
	printf("current %d\n", current);
	printf("location %d\n", location);
	return (0);
}