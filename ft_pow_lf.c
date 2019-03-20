/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow_lf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:47:58 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/19 23:58:11 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <i386/limits.h>


#include <stdio.h>

/*
** __Protection__
** on divise INT64 MAX par notre nombre,
** si le quotient < nombre, trigger sécurité et renvoie 0
** Attention pour les nombre < 0, le prochain nombre sera du signe opposé
** et donc la division est différente selon le cas, INT64 MAX ou INT64 MIN
*/

static long double	ft_modulo_lf(long double x, long double y)
{
	long double ratio;
	ratio = x/y;

	if(x == y * ratio)
		return (0);
	return(x - y * ratio);
}


int8_t	check_result(long double original_x, long double current_x)
{
	if (original_x > 0 && LLONG_MAX / current_x < original_x)
	{
		write(1, "Result too big\n", 15);
		return (1);
	}
	if (original_x < 0)
	{
		if (current_x > 0 && (-LLONG_MAX - 1) / -current_x < -original_x)
		{
			write(1, "Result too big\n", 15);
			return (1);
		}
		if (current_x < 0 && ((-LLONG_MAX) / current_x <= 1
				|| (-LLONG_MAX) / current_x < -original_x))
		{
			write(1, "Result too big\n", 15);
			return (1);
		}
	}
	return (0);
}

long double	calc_pos_exponent(long double x, long double y)
{
	long double original_x;

	original_x = x;
	while (--y > 0)
	{
		x *= original_x;
		// if (y != 1 && check_result(original_x, x))
			// return (0);
		if (x == 1.0/0.0)
		{
			// write(1, "infinity\n", 9);
			break;
		}
	}
	return (x);
}

long double	calc_neg_exponent(long double x, long double y)
{
	long double original_x;

	int64_t i= 0;

	original_x = x;
	while (y++ <= 0)
	{
		x /= original_x;
		// if (y != 1 && check_result(original_x, x))
			// return (0);

		if (x == 0)
		{
			write(1, "zero\n", 5);
			printf("%lld\n", i);
			break;
		}
		i++;
	}
	return (x);
}


long double	known_pow(long double x, long double y)
{
	if (y == 1)
		return (x);
	if (y == 0)
		return (1);
	return (0);
}

long double	zero_one_pow(long double x, long double y)
{
	if (y == 0)
		return (1);
	if (x == 0)
	{
		if (y < 0)
			write(1, "Infinity\n", 9);
		return (0);
	}
	if (x == -1 && (ft_modulo_lf(y, 2)))
		return (-1);
	return (1);
}

long double	ft_pow_lf(long double x, long double y)
{
	if (x == 0 || x == 1)
		return (zero_one_pow(x, y));
	if (y == 0 || y == 1)
		return (known_pow(x, y));
	// if (check_result(x, x))
		// return (0);
	if (y < 0)
		return (calc_neg_exponent(x, y));
	else
		return (calc_pos_exponent(x, y));
}
