/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_nilakantha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 23:56:30 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/16 18:48:50 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

union			u_LfToChar
{
	long double	x;
	char		y[sizeof(long double)];
};

union			u_LfToInt1
{
	long double	x;
	__uint128_t y;
};

union			u_LfToInt2
{
	long double	x;
	struct
	{
		__uint128_t		mantissa : 64;
		__uint128_t		exponent : 15;
		__uint128_t		sign : 1;
		__uint128_t		padding : 48;
	};
};

int16_t ft_printbin(__uint128_t nb, uint8_t size);

long double		pi_nilakantha(uint8_t mantissa_bits)
{
	long double pi;
	int8_t sign;
	long double i;
	union u_LfToInt1 toInt1;
	union u_LfToInt2 toInt2;

	pi = 3;
	sign = 1;
	i = 2;
	while (i < 469000)
	{
		if (sign == 1)
			pi += 4 / (i * (i + 1) * (i + 2));
		if (sign == -1)
			pi -= 4 / (i * (i + 1) * (i + 2));
		i += 2;
		sign = -sign;
	}

	mantissa_bits = 64 - mantissa_bits;

	toInt1.x = pi;
	toInt2.x = pi;


	// toInt1.y >>= mantissa_bits;
	// toInt1.y <<= mantissa_bits;

	// __uint128_t tmp1;
	// __uint128_t tmp2;
	int shift = 127;

	//
	// while (shift > 0)
	// {
	// 	tmp1 = toInt1.y << shift;
	// 	tmp1 = toInt1.y >> 127;
	// 	tmp1 = tmp1 + 48;
	// 	write(1, &tmp1, 1);
	// 	shift--;
	// }
	// write(1, "\n", 1);


	// toInt2.mantissa >>= mantissa_bits;
	// toInt2.mantissa <<= mantissa_bits;

	toInt2.mantissa = 0b1100100000000000000000000000000000000000000000000000000000000000;
	toInt2.sign = 0b0;
	toInt2.exponent = 0b100000000000000;


	char nb = 42;

	// nb = toInt1.y;

	printf("\nprintbin return : %d\n", ft_printbin(nb, sizeof(nb)));
	write(1, "\n", 1);

	shift = 0;
	// while (shift < 64)
	// {
	// 	tmp2 = toInt2.mantissa << shift;
	// 	tmp2 = toInt2.mantissa >> 63;
	// 	tmp2 = tmp2 + 48;
	// 	write(1, &tmp2, 1);
	// 	shift++;
	// }
	// write(1, "\n", 1);

	printf("%.30Lf\n", toInt1.x);
	printf("%.30LF\n", toInt2.x);

	return (toInt1.x);
}
// 0000000000000000000000000010101000000000000000000000000000101010
