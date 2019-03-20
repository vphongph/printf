/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_modulo_lf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:11:42 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/20 00:50:25 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <printf.h>
#include "libft/libft.h"

/*
** La ratio est base 2, attention à la représentation décimale.
** On pourrait croire que 10 % 0.1 = 0 mais la base 2 ne le permet pas.
*/

int32_t		get_exponent(union u_longf ulf)
{
	int32_t expo;
	expo = ulf.y.exponent - EXP_LF;
	return (expo);
}

long double	ft_modulo_lf_test(long double x, long double y)
{
	int64_t ratio_int;
	long double ratio_lf;
	union u_longf ulf;

	if (y == 0 && ((x > 0 && write(1,"+inf\n"RESET, 5))
			|| (x < 0 && write(1,"+inf\n"RESET, 5))))
		return (0);
	ratio_int = x/y;
	ratio_lf = x/y;
	printf("%Lf\n", ratio_lf);
	printf("%lld\n", ratio_int);
	ulf.x = x/y;

	printf("expo : %d\n", get_exponent(ulf));

	if((__int128_t)ratio_lf == ratio_lf)
		return (0);
	return(x - ratio_int * y);
}


int			main()
{
	printf("%.100Lf\n", ft_modulo_lf_test(-65464.0, 1));
}
