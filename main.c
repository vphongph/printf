/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:11:42 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/06 20:24:35 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <i386/limits.h>
#include <sys/syslimits.h>
#define MY_LLONG_MAX 9223372036854775807

int			ft_printf(const char *restrict format, ...);
uint64_t	ft_pow_int(int64_t x, uint64_t y);


double		PI_nilakantha(int round);

int			main()
{
	int64_t i = 0;
	int64_t j = 9223372036854775807;
	// uint64_t k = 0;

	// double duble = 99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999.0;
	// double lipou = 89884656743115795386465259539451236680898848947115328636715040578866337902750481566354238661203768010560056939935696678829394884407208311246423715319737062188883946712432742638151109800623047059726541476042502884419075341171231440736956555270413618581675255342293149119973622969239858152417678164812112068608.000000;

	// ft_printf("qweqweqwe", 123456.15, 'A', 'l', 'i', 'c', 'e');
	// printf("%.100f\n", 123456.15);

	// printf("%lld\n", ft_pow_int(-0x8000000000000000, 2));
	// printf("%lld\n", ft_pow_int(-2, 64));
	// printf("%lld\n", ft_pow_int(-3, 40));
	// printf("%lld\n", ft_pow_int(-4, 32));
	// printf("%lld\n", ft_pow_int(-5, 28));
	// printf("%lld\n", ft_pow_int(-6, 25));
	// printf("%lld\n", ft_pow_int(-7, 25));
	// printf("%lld\n", ft_pow_int(-8, 22));
	// printf("%lld\n", ft_pow_int(-9, 20));
	// printf("%lld\n", ft_pow_int(-10, 19));
	// printf("%lld\n", ft_pow_int(-1 , 99998));
	// printf("%lld\n", ft_pow_int(-12, 20));

	// printf("%lld\n", ft_pow_int(11, 30));
	// printf("%lld\n", ft_pow_int(0x7fffff, 2));
	// printf("%lld\n", ft_pow_int(0x7ffffffff, 2));

	if (j + 1 == i)
	{}

	printf("%lld\n", j + 1);
	printf("%llu\n", 9223372036854775807ULL + 1);
	// printf("%lld\n", ft_pow_int(9223372036854775807 + 1 , 1));
	// printf("%lld\n", ft_pow_int(LLONG_MAX + 1 , 1));
	// if (9223372036854775807 + 1 == k)
	// {}
	// if (LLONG_MAX + 1 == i)
	// {}
	// if (MY_LLONG_MAX + 1 == i)
	// {}


	// printf("%ld\n", 5559917313492231481 * - 11 );

	// printf(" %f\n", pow(987987987987.0, 26));
	// printf(" %f\n", pow(0, -1));
	// printf("%f\n", pow(2, 1024));

	// printf("%lu\n", sizeof(duble));
	// printf("%lu\n", sizeof(lipou));
	return (0);
}

// 9223372036854775807
// 590295599252498284543
