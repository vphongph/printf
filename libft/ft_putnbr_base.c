/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:50:45 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/22 20:12:16 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	fill_base_tab(char *base_tab)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < 43)
		if (i <= 9 || i >= 17)
			base_tab[++j] = '0' + i;
}

uint8_t		ft_putnbr_base(__int128_t nb, uint8_t base)
{
	__uint128_t	nbr;
	char		base_tab[36];
	uint8_t		i;

	if (base < 2 || base > 36)
		return (0);
	if (base == 10 && nb < 0)
		write(1, "-", 1);
	fill_base_tab(base_tab);
	nbr = nb < 0 ? -nb : nb;
	i = 1;
	if (nbr > base - 1)
		i += ft_putnbr_base(nbr / base, base);
	write(1, &base_tab[nbr % base], 1);
	return (i);
}
