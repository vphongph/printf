/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:11:42 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/16 23:59:06 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <i386/limits.h>
#include <sys/syslimits.h>
#include "libft/libft.h"
#define MY_LLONG_MAX 9223372036854775807
#define MY_PI 3.14159265358979323846 2643383279502884L

long double		pi_nilakantha(uint8_t mantissa_bits);
int16_t ft_printbin(__uint128_t nb, uint8_t size, uint8_t format_0b);

int			main()
{

	union u_lftoint1 toint1;
	union u_lftoint2 toint2;

	toint1.x = pi_nilakantha(5);
	toint2.x = pi_nilakantha(5);
	printf("        %.36Lf\n", 3.141592653589793238462643383279502884L);
	printf("math pi 3.141592653589793238462643383279502884\n");


	// int nbbits = 64;

	// toInt2.mantissa = 0b1100100000000000000000000000000000000000000000000000000000000000;
	// toInt2.sign = 0b0;
	// toInt2.exponent = 0b100000000000000;


	// printf("\nprintbin return : %d\n", ft_printbin(toInt1.y, nbbits, 'b'));
	// ft_printbin(toInt1.y, nbbits, 'b');
	write(1, "\n", 1);

	// printf("\nprintbin return : %d\n", ft_printbin(toInt2.mantissa, nbbits, 'b'));
	// ft_printbin(toInt2.mantissa, nbbits, 'b');
	write(1, "\n", 1);

	printf("%.30Lf\n", toint1.x);
	printf("%.30LF\n", toint2.x);



	return (0);
}
