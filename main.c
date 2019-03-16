/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:11:42 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/15 22:54:57 by vphongph         ###   ########.fr       */
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

//h
extern const double	my_pi;

//c
const double	my_pi = 3.14159265;

int			ft_printf(const char *restrict format, ...);
uint64_t	ft_pow_int(int64_t x, uint64_t y);
double		PI_nilakantha(int mantissa_bits);


int			main()
{

	int64_t l = 3037000000;
	int64_t m = 2;

	(void)l;
	(void)m;


	printf("    f : %f\n", M_PI);
	printf(" f 25 : %.25f\n", M_PI);
	printf("   lf : %lf\n", M_PI);
	printf("lf 25 : %.25lf\n", M_PI);
	printf("   Lf : %Lf\n", (long double)M_PI);
	printf("Lf 25 : %.25Lf\n", (long double)M_PI);

	printf("    e : %.25e\n", M_PI);

	printf("\nmath pi 3.14159265358979323846\n");

	printf("\n     double %.29f\n", 0.0123456789321654987147258369);
	printf("long double %.29Lf\n", 0.0123456789321654987147258369L);

	return (0);
}
