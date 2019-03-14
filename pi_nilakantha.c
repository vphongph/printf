/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_nilakantha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 23:56:30 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/15 00:20:00 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

union			u_LfToChar
{
	long double	x;
	char		y[sizeof(long double)];
};

union			u_LfToInt
{
	long double	x;
	__int128	y;
};

long double		pi_nilakantha(int round)
{
	long double pi;
	int8_t sign;
	long double i;
	(void)round;

	union u_LfToInt test;

	pi = 3;
	sign = 1;
	i = 2;

	// while (i < 469000)

	while (i < 469000)
	{
		if (sign == 1)
			pi += 4 / (i * (i + 1) * (i + 2));
		if (sign == -1)
			pi -= 4 / (i * (i + 1) * (i + 2));
		i += 2;
		sign = -sign;
	}

	test.x = pi;

	test.y = test.y >> round;
	test.y = test.y << round;

	return (test.x);
}
