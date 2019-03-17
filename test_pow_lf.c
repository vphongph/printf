/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pow_lf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:11:42 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/17 20:43:58 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <i386/limits.h>
#include <sys/syslimits.h>
#include "libft/libft.h"
#include <fcntl.h>
#define MY_LLONG_MAX 9223372036854775807


long double	ft_modulo_lf(long double x, long double y);
long double	ft_pow_lf(long double x, long double y);


int			main()
{
	int64_t j = 9223372036854775807;
	int64_t l = 2097;
	int64_t m = 2;

	(void)j;
	(void)l;
	(void)m;


	// printf("%Lf\n", ft_pow_lf(-LLONG_MAX -1 , 2));
	printf("%.Lf\n", ft_pow_lf(-2, 16385));
	// printf("%lld\n", ft_pow_lf(-3, 40));
	// printf("%lld\n", ft_pow_lf(-4, 32));
	// printf("%lld\n", ft_pow_lf(-5, 28));
	// printf("%lld\n", ft_pow_lf(-6, 25));
	// printf("%lld\n", ft_pow_lf(-7, 23));
	// printf("%lld\n", ft_pow_lf(-8, 22));
	// printf("%lld\n", ft_pow_lf(-9, 20));
	// printf("%lld\n", ft_pow_lf(-10, 19));
	// printf("%lld\n", ft_pow_lf(-11, 19));
	// printf("%lld\n", ft_pow_lf(-12, 18));
	// printf("%lld\n", ft_pow_lf(-13, 18));
	// printf("%lld\n", ft_pow_lf(-14, 17));
	// printf("%lld\n", ft_pow_lf(-15, 17));
	// printf("%lld\n", ft_pow_lf(-16, 16));
	// printf("%lld\n", ft_pow_lf(-17, 16));
	// printf("%lld\n", ft_pow_lf(-18, 16));
	// printf("%lld\n", ft_pow_lf(-19, 15));
	// printf("%lld\n", ft_pow_lf(-20, 15));
	// printf("%lld\n", ft_pow_lf(-21, 15));
	// printf("%lld\n", ft_pow_lf(-22, 15));
	// ...
	// printf("%lld\n", ft_pow_lf(-55109, 4));
	// printf("%lld\n", ft_pow_lf(-2097153, 3));
	// printf("%lld\n", ft_pow_lf(-3037000500, 2));
	//
	// printf("%lld\n", ft_pow_lf(55109, 4));
	// printf("%lld\n", ft_pow_lf(2097152, 3));
	// printf("%lld\n", ft_pow_lf(3037000500, 2));

	// printf("%lld\n", ft_pow_lf(0, -100000));

	// FILE* fd;
	//
	// fd = popen("find .", "r");
	// char buff[101];
	// while (fgets(buff, 100, fd))
	// 	printf("%s", buff);
	// return (0);
}
