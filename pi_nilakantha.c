/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_nilakantha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 23:56:30 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/17 01:48:50 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"

static long double	round_pi(long double pi, uint8_t mantiss_prec)
{
	union u_longf ulf;

	ulf.x = pi;
	mantiss_prec = 64 - mantiss_prec;
	ulf.y.mantissa >>= mantiss_prec;
	ulf.y.mantissa <<= mantiss_prec;
	return (ulf.x);
}

long double			pi_nilakantha(uint8_t mantiss_prec)
{
	long double	pi;
	long double	i;
	int8_t		sign;

	pi = 3;
	i = 2;
	sign = 1;
	if (mantiss_prec == 0
		|| (mantiss_prec > 64 && write(1, "mantissa precision NON OK\n", 26)))
		return (0);
	while (i < 469000)
	{
		if (sign == 1)
			pi += 4 / (i * (i + 1) * (i + 2));
		if (sign == -1)
			pi -= 4 / (i * (i + 1) * (i + 2));
		i += 2;
		sign = -sign;
	}
	return (round_pi(pi, mantiss_prec));
}
