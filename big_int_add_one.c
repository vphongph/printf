/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_int_add_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 06:05:18 by vphongph          #+#    #+#             */
/*   Updated: 2019/06/30 07:05:32 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int8_t	big_int_add_one(__uint128_t *tab_nb, int16_t index, __uint128_t one)
{
	__uint128_t tab_nb_tmp[BIG_INT_TAB];

	if (!tab_nb || index < 0 || index >= BIG_INT_TAB)
	{
		ft_putstr_fd_v2(RED"Big int add one -> ∅\n"RESET, 2);
		return (-1);
	}
	ft_bzero_v2(tab_nb_tmp, sizeof(tab_nb_tmp));
	tab_nb_tmp[index] = one;
	big_int_add(tab_nb, tab_nb_tmp, BIG_INT_TAB);
	return (0);
}
