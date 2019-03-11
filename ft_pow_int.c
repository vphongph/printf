/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:47:58 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/10 23:08:24 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <i386/limits.h>

/*
** __Protection__
** on divise val max par notre nombre,
** si le quotient > nombre, trigger sécurité et renvoie 0
**
*/

int8_t	check_result(int64_t original_x, int64_t current_x)
{
	if (original_x > 0)
	{
		if (LLONG_MAX / current_x < original_x)
			return (1);
	}
	if (original_x < 0)
	{
		if (current_x > 0)
		{
			if ((-LLONG_MAX - 1) / -current_x < -original_x)
			{
				write(1, "Result too big\n", 5);
				return (1);
			}
		}
		if (current_x < 0)
		{
			printf("3 / : %lld\n",(-LLONG_MAX) / current_x);
			if ((-LLONG_MAX) / current_x < -original_x || (-LLONG_MAX) / current_x <= 1)
			{
				write(1, "Result too big\n", 5);
				return (1);
			}
		}
	}

	return (0);
}

int64_t calc_result(int64_t x, int64_t y)
{
	int original_x;

	original_x = x;
	while (--y > 0)
	{
		// printf("X : %lld\n", x * original_x);
		x *= original_x;
		if (y != 1 && check_result(original_x, x))
			return (0);
	}
	return (x);
}

int64_t	known_pow(int64_t x, int64_t y)
{
	if (y == 1)
		return (x);
	if (y == 0)
		return (1);
	return (0);
}

int64_t	zero_one_pow(int64_t x, int64_t y)
{
	if (y == 0)
		return (1);
	if (x == 0)
	{
		if (y < 0)
			write(1, "Infinity\n", 9);
		return (0);
	}
	if (x == -1 && y & 1)
		return (-1);
	return (1);
}

int64_t	ft_pow_int(int64_t x, int64_t y)
{
	if (x == 0 || x == 1 || x == -1)
		return (zero_one_pow(x, y));
	if (y < 2)
		return (known_pow(x, y));
	if (check_result(x, x))
		return (0);
	return (calc_result(x, y));
}
