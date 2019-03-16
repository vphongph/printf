/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_nilakantha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 23:56:30 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/17 00:02:05 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

static long double round_pi (lond double pi, uint8_t mantissa_round)
{
	union u_lftoint1 toint1;
	union u_lftoint2 toint2;



}

long double		pi_nilakantha(uint8_t mantissa_round)
{

	long double pi;
	long double i;
	int8_t sign;

	pi = 3;
	i = 2;
	sign = 1;
	while (i < 469000)
	{
		if (sign == 1)
			pi += 4 / (i * (i + 1) * (i + 2));
		if (sign == -1)
			pi -= 4 / (i * (i + 1) * (i + 2));
		i += 2;
		sign = -sign;
	}

	mantissa_round = 64 - mantissa_round;

	toInt1.x = pi;
	toInt2.x = pi;

	int nbbits = 64;

	// toInt1.y >>= mantissa_bits;
	// toInt1.y <<= mantissa_bits;

	// toInt2.mantissa >>= mantissa_bits;
	// toInt2.mantissa <<= mantissa_bits;

	// toInt2.mantissa = 0b1100100000000000000000000000000000000000000000000000000000000000;
	// toInt2.sign = 0b0;
	// toInt2.exponent = 0b100000000000000;

	return (round_pi(pi ,mantissa_round));
}
