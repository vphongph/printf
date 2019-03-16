/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:11:42 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/16 03:47:47 by vphongph         ###   ########.fr       */
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
#define MY_PI 3.14159265358979323846
// #define __MATH_LONG_DOUBLE_CONSTANTS

long double		pi_nilakantha(uint8_t mantissa_bits);


int			main()
{

	// int64_t i = MY_LLONG_MAX;

	// i = i + 1;

	pi_nilakantha(5);
	// printf("        %.36Lf\n", 3.141592653589793238462643383279502884L);
	// printf("math pi 3.141592653589793238462643383279502884\n");

	// printf("%lu\n", sizeof(long double) * 8);


	return (0);
}
