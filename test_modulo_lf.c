/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_modulo_lf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:11:42 by vphongph          #+#    #+#             */
/*   Updated: 2019/04/01 15:14:01 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <printf.h>
#include "libft/libft.h"
#include <string.h>
#include <math.h>

/*
** La ratio est base 2, attention à la représentation décimale.
** On pourrait croire que 10 % 0.1 = 0 mais la base 2 ne le permet pas.
** ATTENTION à bien préciser long double si on entre un float litéral en parma(1.0L)
, sinon perte
*8 de précision, la mantisse ne vaut pas 64 bits
** Si x/2
** ATTENTION arrondi, perte de precision quand exponent * mantisse ne permet pas de representer un nombre, un arrondis s'opère, modulo pas 100% fiable, donc à appliquer avec valeurs safe
** modulo boo, safer
** TOUJOURS BIEN SURVEILLER NB BIT pour EXPONENT OU AUTRE< TRES DANGEREUX
** Pas super fiable, avec arrondis, perte de precision etc... ou grand nombre divisé par 2.1, pas fiable

*/
//
// static int8_t	check_exponent(long double x, long double y)
// {
// 	t_longf ratio;
//
// 	ratio.x = x/y;
// 	if (lf_get_exponent(ratio.y.exponent) >= 63)
// 	{
// 		printf("expo : %d\n", lf_get_exponent(ratio.y.exponent));
// 		if (y != 1.L && y != -1.L && y != 2.L && y != -2.L)
// 			printf(RED"modulo inapplicable\n"RESET);
// 		return (1);
// 	}
// 	return (0);
// }
//


long double lf_abs(long double x)
{
	return(x < 0 ? -x : x);
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
		|| ratio.y.exponent == 0b111111111111111)
	{
		printf("expo : %d\n", lf_get_exponent(ratio.y.exponent));
		printf(RED"modulo inapplicable\n"RESET);
		return (1);
	}
	return (0);
}

long double		lf_modulo_test(long double x, long double y)
{
	t_longf ratio_lf1;
	t_longf ratio_lf2;
	__int128_t ratio_int;

	if (check_xy(x, y))
		return (0);
	// if (check_exponent(x, y))
		// return (0);

	ratio_lf1.x = x/y;
	ratio_lf2.x = lf_remove_decimal(x/y);
	ratio_int = x/y;

	printf("ratio lf1  : %.50Lf\n", ratio_lf1.x);
	printf("expo lf1   : %d\n", lf_get_exponent(ratio_lf1.y.exponent));
	printf("ratio lf2  : %.50Lf\n", ratio_lf2.x);
	printf("ratio int\n");
	ft_putnbr_base(ratio_int, 10);
	printf("\n");

	if (lf_abs(y) > lf_abs(x))
		return (x);
	// if (ratio_lf1.x == ratio_lf2.x)
		// return (0);
	return (x - (__int128_t)(x/y) * y);
}

int			main()
{
	t_longf ulf1;
	t_longf ulf2;
	t_longf ulf3; (void)ulf3;
	t_longf ulf4; (void)ulf4;


	ulf1.y.sign = 1;
	// ulf1.y.exponent = 0b111111111111111;
	ulf1.y.exponent = lf_set_exponent(63);
	ulf1.y.mantissa = 0b1000000000000000000000000000000000000000000000000000000000000001;
	// ulf1.y.exponent = lf_set_exponent(16383);
	// ulf1.y.mantissa = 0b0000000000000000000000000000000000000000000000000000000000000000;
	// ulf1.x = 2.0000000000000000001084202172485L;
	// ulf1.x = 2.0000000000000000001084202172486L;
	        // 0000000000000000002
	ulf1.x = 2.1L;
	// ulf1.x = 2.9L;
	// ulf1.x = 3.0L;
	// ulf1.x = 3.0L;


	ulf2.y.sign = 0;
	// ulf2.y.exponent = 0b000000000000001;
	ulf2.y.exponent = lf_set_exponent(64);
	ulf2.y.mantissa = 0b1000000000000000000000000000000000000000000000000000000000000001;
	// ulf2.y.exponent = lf_set_exponent(16383);
	// ulf2.y.mantissa = 0b0000000000000000000000000000000000000000000000000000000000000000;
	// ulf2.x = 1537228672809129301.375L;
	// ulf2.x *= 2.0L;
	// ulf2.x = 2.2L;
	ulf2.x = 18446744073709551618.0L;

	// 9223372036854775808 / 2.9


	ft_printbin(ulf2.y.sign, 1, 'b');
	printf("\n");
	ft_printbin(ulf2.y.exponent, 15, 'b');
	printf("\n");
	printf("expo ulf2 : %d\n", lf_get_exponent(ulf2.y.exponent));
	printf("\n");
	ft_printbin(ulf2.y.mantissa, 64, 'b');
	printf("\n");
	printf("ulf2.x : %.70Lf\n", ulf2.x);
	printf("\n");

	ft_printbin(ulf1.y.sign, 1, 'b');
	printf("\n");
	ft_printbin(ulf1.y.exponent, 15, 'b');
	printf("\n");
	ft_printbin(ulf1.y.mantissa, 64, 'b');
	printf("\n");
	printf("ulf1.x : %.70Lf\n", ulf1.x);
	printf("\n");

	ulf3.x = ulf2.x / ulf1.x;

	ft_printbin(ulf3.y.sign, 1, 'b');
	printf("\n");
	ft_printbin(ulf3.y.exponent, 15, 'b');
	printf("\n");
	ft_printbin(ulf3.y.mantissa, 64, 'b');
	printf("\n");
	printf("ulf3.x : %.70Lf\n", ulf3.x);
	printf("\n");


	// ulf2.x = lf_set_nan_inf('i', 0);
	// ulf2.x /= ulf1.x;
	// ulf2.x *= ulf1.x;
	// ulf2.x *= 2.0;
	// ulf2.x += 0.0L;



	// ft_printbin(ulf2.y.sign, 1, 'b');
	// printf("\n");
	// ft_printbin(ulf2.y.exponent, 15, 'b');
	// printf("\n");
	// ft_printbin(ulf2.y.mantissa, 64, 'b');
	// printf("\n");
	// printf("ulf2.x : %.50Lf\n", ulf2.x);
	// printf("\n");
	// if (ulf2.x == 0)
		// printf(YELLOW"ulf2.x == 0\n"RESET);

	// ft_printbin(ulf1.y.sign, 1, 'b');
	// printf("\n");
	// ft_printbin(ulf1.y.exponent, 15, 'b');
	// printf("\n");
	// ft_printbin(ulf1.y.mantissa, 64, 'b');
	// printf("\n");
	// printf("ulf1.x : %.50Lf\n", ulf1.x);
	// printf("\n");

	// printf("ulf2.x removed : %.50Lf\n", lf_remove_decimal(ulf2.x));
	// if (lf_remove_decimal(ulf2.x) == 0)
		// printf(YELLOW"remove == 0 \n"RESET);

	// printf("ulf2.x removed + 1 : %.50Lf\n", lf_remove_decimal(ulf2.x) + 1);

	// if (lf_check_nupi(ulf2.x))
		// printf(ORDER"AIE\n"RESET);
	// if (ulf2.x == ulf2.x)
		// printf(ALLIANCE"HEHE\n"RESET);

	if ((ulf3.x = lf_modulo_test(ulf2.x, ulf1.x)) == 0)
		printf(YELLOW"yeah\n");
	else
		printf("%Lf\n", ulf3.x);

	printf("%f\n", fmod(18446744073709551618.0,2.1));

	ulf3.y.sign = 0;
	ulf3.y.exponent = lf_set_exponent(0);
	ulf3.y.mantissa = 0b1000000000000000000000000000000000000000000000000000000000000000;

	// printf("%La\n", 2.5L);
}
// 000000001

uint64_t l = 9223372036854775808ULL;
/*
QUESTION ???
Exposant positif mais mantisse null, c'est pas 0 c'est quoi ?
ARITHMETIQUE des float ? tres petit nb + nombre normal ?
Pseudo 0 + un autre ?
** LES nan ne se valent pas ? les inf non plus ?
** ATTENTION Arithmetique denormal, pour expo -16383, mantisse -> expo+1
** Si nb unnormal, impossible de faire arithmetique dessus sauf * 1 et * -1
** devient NaN
*/
