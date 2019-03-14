/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:11:42 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/15 00:17:44 by vphongph         ###   ########.fr       */
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
#define __MATH_LONG_DOUBLE_CONSTANTS

long double		pi_nilakantha(int round);


int			main()
{

	printf("        %.36Lf\n", pi_nilakantha(58));
	printf("        %.36Lf\n", 3.141592653589793238462643383279502884L);
	printf("math pi 3.141592653589793238462643383279502884\n");


	return (0);
}
