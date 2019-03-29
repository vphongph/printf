/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo_lf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:11:42 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/28 15:32:07 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <printf.h>
#include "libft/libft.h"

/*
** La ratio est base 2, attention à la représentation décimale.
** On pourrait croire que 10 % 0.1 = 0 mais la base 2 ne le permet pas.
** ATTENTION à bien préciser long double si on entre un float litéral en parma(1.0L)
, sinon perte
*8 de précision, la mantisse ne vaut pas 64 bits
** ATTENTION au pseudo 0 != 0
*/

int16_t		get_exponent(int16_t to_get)
{
	if (to_get < 0)
	{
		ft_putstr_fd_v2(RED"not a exponent\n"RESET, 2);
		return (0);
	}
	return (to_get - EXP_LF);
}

int16_t	set_exponent(int16_t to_set)
{
	if (to_set < -EXP_LF || to_set > EXP_LF + 3)
	{
		ft_putstr_fd_v2(RED"exponent non ok\n"RESET, 2);
		return (0);
	}
	return (to_set + EXP_LF);
}

/*
** ATTENTION au PSEUDO INF != INF
** ATTENTION au PSEUDO NaN != NaN
** ATTENTION au NaN non défini, non comparable
*/

long double	set_nan_inf(int8_t c, int8_t sign)
{
	t_longf ulf;

	ulf.y.exponent = 0b111111111111111;

	if (sign == 0 || sign == 1)
		ulf.y.sign = sign;
	else
		return (0);
	if (c == 'n')
	{
		ulf.y.mantissa = (1L << 63) + 1;
		return (ulf.x);
	}
	if (c == 'i')
	{
		ulf.y.mantissa = 1L << 63;
		return (ulf.x);
	}
	return (0);
}


long double remove_decimal(long double x)
{
	t_longf ulf;
	int32_t	shift;

	ulf.x = x;

	if ((shift = 64 - get_exponent(ulf.y.exponent)) >= 64)
		ulf.x = 0;
	else if (shift > 0)
	{
		ulf.y.mantissa >>= shift;
		ulf.y.mantissa <<= shift;
	}
	return (ulf.x);
}

static int8_t	check_xy(long double x, long double y)
{
	t_longf ux;
	t_longf uy;
	t_longf ratio;

	ux.x = x;
	uy.x = y;
	ratio.x = x/y;
	if (ux.y.exponent == 0b111111111111111
		|| uy.y.exponent == 0b111111111111111
		|| ratio.y.exponent == 0b1111111111111111
		|| get_exponent(ratio.y.exponent) >= 64)
	{
		printf("expo : %d\n", get_exponent(ratio.y.exponent));
		printf(RED"modulo inapplicable\n"RESET);
		return (1);
	}
	return (0);
}

long double		ft_modulo_lf_test(long double x, long double y)
{
	t_longf ratio_lf1;
	t_longf ratio_lf2;

	if (check_xy(x, y))
		return (0);

	ratio_lf1.x = x/y;
	ratio_lf2.x = remove_decimal(x/y);

	printf("ratio lf1  : %.50Lf\n", ratio_lf1.x);
	printf("ratio lf2  : %.50Lf\n", ratio_lf2.x);


	if (ratio_lf1.x == ratio_lf2.x)
		return (0);
	return(x - ratio_lf2.x * y);
}

int8_t	ft_modulo_lf_two(long double x)
{
	long double y = 2;
	while ((y) < x)
		y += 2;
	if (y == x)
		return (0);
	return (1);
}


int			main()
{
	t_longf ulf1;
	t_longf ulf2;
	t_longf ulf3; (void)ulf3;

	ulf1.y.sign = 0;
	// ulf1.y.exponent = 0b111111111111110;
	ulf1.y.exponent = set_exponent(-16382);
	ulf1.y.mantissa = 0b1000000000000000000000000000000000000000000000000000000000000000;

	ulf2.y.sign = 0;
	// ulf2.y.exponent = 0b000000000000001;
	ulf2.y.exponent = set_exponent(65);
	ulf2.y.mantissa = 0b1000000000000000000000000000000000000000000000000000000000000001;

	// ft_printbin(ulf2.y.exponent, 15, 'b');
	// printf("\n");
	// printf("\n");


	// if (ulf2.x == 0)
		// printf("C'EST OK\n");

	// ulf2.x *= 2.0;
	// ulf2.x = set_nan_inf('i', 0);
	// ulf2.x -= 1;
	// ulf2.x /= 2;


	// ft_printbin(ulf2.y.sign, 1, 'b');
	// printf("\n");
	// ft_printbin(ulf2.y.exponent, 15, 'b');
	// printf("\n");
	// ft_printbin(ulf2.y.mantissa, 64, 'b');
	// printf("\n");

	// printf("ulf1.x : %Lf\n", ulf1.x);
	// printf("ulf2.x : %.50Lf\n", ulf2.x);
	// printf("modulo : %.170Lf\n", ft_modulo_lf_test(10.0L, 1000000L));

	// if (ulf2.y.exponent == 0b111111111111111)
		// printf(ORDER"WAOUU\n"RESET);
	// if (ulf2.x == ulf2.x)
		// printf(ALLIANCE"WAOUU\n"RESET);
	// if (1./ulf1.x == set_nan_inf('i',0))
		// printf(FEDERATION"WAOUU\n"RESET);

	if ((ulf3.x = ft_modulo_lf_test(1.0L, 0.1L)) == 0)
		printf(YELLOW"yeah\n");
	else
		printf("%Lf\n", ulf3.x);

}


/*
QUESTION ???
Exposant positif mais mantisse null, c'est pas 0 c'est quoi ?
ARITHMETIQUE des float ? tres petit nb + nombre normal ?
Pseudo 0 + un autre ?
** LES nan ne se valent pas ? les inf non plus ?
*/
