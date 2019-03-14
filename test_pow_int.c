/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pow_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:11:42 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/13 23:54:56 by vphongph         ###   ########.fr       */
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

uint64_t	ft_pow_int(int64_t x, uint64_t y);
double		PI_nilakantha(int round);


int			main()
{
	int64_t j = 9223372036854775807;
	int64_t l = 2097;
	int64_t m = 2;

	(void)j;
	(void)l;
	(void)m;

	printf("%lld\n", ft_pow_int(-LLONG_MAX -1 , 2));
	// printf("%lld\n", ft_pow_int(-2, 64));
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
	// printf("%lld\n", ft_pow_int(-55109, 4));
	// printf("%lld\n", ft_pow_int(-2097153, 3));
	// printf("%lld\n", ft_pow_int(-3037000500, 2));
	//
	// printf("%lld\n", ft_pow_int(55109, 4));
	// printf("%lld\n", ft_pow_int(2097152, 3));
	// printf("%lld\n", ft_pow_int(3037000500, 2));

	// printf("%lld\n", ft_pow_int(0, -100000));


	// while (l <= 1000000000000000000)
	// {
	// 	while (ft_pow_int(l, m) != 0)
	// 		m++;
	// 	printf("%lld, %lld\n", l, m);
	// 	if (m == 4)
	// 		sleep(3);
	// 	m = 2;
	// 	l++;
	// }

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

	return (0);
}
//
