/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:11:42 by vphongph          #+#    #+#             */
/*   Updated: 2019/07/16 04:03:00 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <i386/limits.h>
#include <sys/syslimits.h>
#include "libft.h"
#define MY_LLONG_MAX 9223372036854775807
#define MY_PI 3.14159265358979323846 2643383279502884L

long double		pi_nilakantha(uint8_t mantissa_precision);
int16_t ft_printbin(__uint128_t nb, uint8_t size, uint8_t format_0b);

int			main()
{
	// union u_lftoint1 toint1;
	union u_lfloat ulf;

	ulf.x = pi_nilakantha(64);
	printf("        %.62Lf\n", 3.141592653589793238462643383279502884L);

	// printf("        %.36Lf\n", toint1.x);
	printf("        %.62Lf\n", ulf.x);
	printf("math pi 3.141592653589793238462643383279502884\n");

	ft_printbin(ulf.y.mantissa, 64, 0);
	printf("\n");

	ulf.x = 3.141592653589793238462643383279502884L;
	ft_printbin(ulf.y.mantissa, 64, 0);
	printf("\n");


	// ulf.y.mantissa = 0b1100100000000000000000000000000000000000000000000000000000000000;
	// ulf.y.sign = 0b0;
	// ulf.y.exponent = 0b100000000000000;


	// printf("\nprintbin return : %d\n", ft_printbin(toint1.y, nbbits, 'b'));
	// ft_printbin(toint1.y, nbbits, 'b');

	// printf("\nprintbin return : %d\n", ft_printbin(ulf.y.mantissa, nbbits, 'b'));
	// ft_printbin(ulf.mantissa, nbbits, 'b');

	// printf("        %.36Lf\n", toint1.x);
	// printf("        %.62Lf\n", ulf.x);

	return (0);
}
