/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_modulo_lf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:11:42 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/21 17:39:10 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <printf.h>
#include "libft/libft.h"

/*
** La ratio est base 2, attention à la représentation décimale.
** On pourrait croire que 10 % 0.1 = 0 mais la base 2 ne le permet pas.
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

long double	set_nan_inf(int8_t c, int8_t sign)
{
	t_longf ulf;

	ulf.y.exponent = 0b111111111111111;

	if (sign == 0)
		ulf.y.sign = 0;
	if (sign == 1)
		ulf.y.sign = 1;
	if (c == 'n')
	{
		ulf.y.mantissa = 1;
		return (ulf.x);
	}
	if (c == 'i')
	{
		ulf.y.mantissa = 0;
		return (ulf.x);
	}
	return (0);
}

long double	ft_modulo_lf_test(long double x, long double y)
{
	int64_t ratio_int;
	long double ratio_lf;
	t_longf ulf;

	if (y == 0 && ((x > 0 && ft_putstr_fd_v2(RED"+inf\n"RESET, 2))
			|| (x < 0 && ft_putstr_fd_v2(RED"-inf\n"RESET, 2))))
		return (0);
	ulf.x = x;
	if (get_exponent(ulf.y.exponent) >= 64)
		;

	ratio_int = x/y;
	ratio_lf = x/y;
	printf("x : %.50Lf\n", x);
	printf("ratio lf  : %.50Lf\n", ratio_lf);
	printf("ratio int : %lld\n", ratio_int);
	ulf.x = x;
	printf("expo x   : %d\n", get_exponent(ulf.y.exponent));
	ulf.x = y;
	printf("expo y   : %d\n", get_exponent(ulf.y.exponent));
	ulf.x = x/y;
	printf("expo x/y : %d\n", get_exponent(ulf.y.exponent));

	if (x == 0)
		printf(GREEN"EH BEH\n"RESET);
	if (ratio_lf == 0)
		printf(BLUE"eh beh\n"RESET);
	if(ratio_lf == ratio_int)
	{
		printf(YELLOW"YEAH\n"RESET);
		return (0);
	}
	return(x - ratio_int * y);
}


int			main()
{
	t_longf ulf1;
	t_longf ulf2;

	ulf1.y.sign = 0;
	ulf1.y.exponent = 0b111111111111110;
	ulf1.y.mantissa = 0b1111111111111111111111111111111111111111111111111111111111111111;

	ulf2.y.sign = 0;
	ulf2.y.exponent = 0b111111111111111;
	ulf2.y.mantissa = 0b1000000000000000000000000000000000000000000000000000000000000000;

	ulf2.x = set_nan_inf('i',10);
	ft_printbin(ulf2.y.sign, 1, 'b');
	printf("\n");
	ft_printbin(ulf2.y.exponent, 15, 'b');
	printf("\n");
	ft_printbin(ulf2.y.mantissa, 64, 'b');
	printf("\n");

	// printf("ulf1.x : %Lf\n", ulf1.x);
	printf("ulf2.x : %Lf\n", ulf2.x);
	// printf("ulf.x : %.50Lf\n", 1.0L/0.0L);
	// printf("modulo : %.50Lf\n", ft_modulo_lf_test(ulf2.x, ulf1.x));


	// printf("%.10Lf\n", ft_modulo_lf_test(100000000000000000001.645455, 3));
}
