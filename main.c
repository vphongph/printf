/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:11:42 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/11 03:06:00 by vphongph         ###   ########.fr       */
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

int			ft_printf(const char *restrict format, ...);
uint64_t	ft_pow_int(int64_t x, uint64_t y);
double		PI_nilakantha(int round);




int			main()
{

	__int128 lol;
	int64_t i = 0;
	int64_t j = 9223372036854775807;
	int64_t k = 0;
	(void)i;
	(void)j;
	(void)k;

	int64_t l = 3037000000;
	int64_t m = 2;

	(void)l;
	(void)m;
	(void)lol;


	// double duble = 99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999.0;
	// double lipou = 89884656743115795386465259539451236680898848947115328636715040578866337902750481566354238661203768010560056939935696678829394884407208311246423715319737062188883946712432742638151109800623047059726541476042502884419075341171231440736956555270413618581675255342293149119973622969239858152417678164812112068608.000000;

	// ft_printf("qweqweqwe", 123456.15, 'A', 'l', 'i', 'c', 'e');
	// printf("%.100f\n", 123456.15);

	// printf("%lld\n", ft_pow_int(-LLONG_MAX - 1 , 2));
	// printf("%lld\n", ft_pow_int(2, 64));
	// printf("%lld\n", ft_pow_int(-3, 40));
	// printf("%lld\n", ft_pow_int(-4, 32));
	// printf("%lld\n", ft_pow_int(-5, 28));
	// printf("%lld\n", ft_pow_int(-6, 25));
	// printf("%lld\n", ft_pow_int(-7, 23));
	// printf("%lld\n", ft_pow_int(-8, 22));
	// printf("%lld\n", ft_pow_int(-9, 20));
	// printf("%lld\n", ft_pow_int(-10, 19));
	// printf("%lld\n", ft_pow_int(-11, 19));
	// printf("%lld\n", ft_pow_int(-12, 18));
	// printf("%lld\n", ft_pow_int(-13, 18));
	// printf("%lld\n", ft_pow_int(-14, 17));
	// printf("%lld\n", ft_pow_int(-15, 17));
	// printf("%lld\n", ft_pow_int(-16, 16));
	// printf("%lld\n", ft_pow_int(-17, 16));
	// printf("%lld\n", ft_pow_int(-18, 16));
	// printf("%lld\n", ft_pow_int(-19, 15));
	// printf("%lld\n", ft_pow_int(-20, 15));
	// printf("%lld\n", ft_pow_int(-21, 15));
	// printf("%lld\n", ft_pow_int(-22, 15));
	// ...
	// printf("%lld\n", ft_pow_int(-2097152, 4));
	// printf("%lld\n", ft_pow_int(-2097153, 3));
	// printf("%lld\n", ft_pow_int(-3037000500, 2));

	// printf("%lld\n", ft_pow_int(2097151, 4));
	// printf("%lld\n", ft_pow_int(2097152, 3));
	// printf("%lld\n", ft_pow_int(3037000500, 2));


	// while (l <= 10000000000000)
	// {
		// while (ft_pow_int(l, m) != 0)
			// m++;
		// printf("%lld, %lld\n", l, m);
		// if (m == 2)
			// sleep(3);
		// m = 2;
		// l++;
	// }

	// printf("%lld\n", ft_pow_int(11, 30));
	// printf("%lld\n", ft_pow_int(0x7fffff, 3));
	// printf("%lld\n", ft_pow_int(0x7ffffffff, 2));

	// if (j + 1 == i)
	// {}

	// printf("%lld\n", j + 1);
	// printf("%lld\n", ft_pow_int(9223372036854775807 + 1 , 1));
	// printf("%lld\n", ft_pow_int(LLONG_MAX + 1 , 1));
	// if (9223372036854775807 + 1 == k)
	// {}
	// if (LLONG_MAX + 1 == i)
	// {}
	// if (MY_LLONG_MAX + 1 == i)
	// {}
	// if (j + 1 == i)
	// {}



	// printf("%ld\n", 5559917313492231481 * - 11 );

	// printf(" %f\n", pow(98554545454880000.3, 26.154545454545454545454));

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

	printf("int128 %lu\n", sizeof(lol));

	// 3.141592653589793115997963468544
	// printf(" %f\n", pow(0, -1));
	// printf("%f\n", pow(2, 1024));

	// printf("%lu\n", sizeof(duble));
	// printf("%lu\n", sizeof(lipou));
	return (0);
}
