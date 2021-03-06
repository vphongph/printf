/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lf_check_nupi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 01:14:21 by vphongph          #+#    #+#             */
/*   Updated: 2019/07/22 02:32:53 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

/*
** Check Not a Number, Unnormal, Pseudo infinity
** Characteristics of these values on Wikipedia, extended precision
** Inf != pseudo Inf
** NaN != NaN
** Unnormal != Unnormal and no arithmetic permitted except * 1
**
** Could be re-worked.
** A other way to determine nupi, is to check if equal to itself.
** None of them are equal to themselve. 
** Arithmetic on them are not permitted.
*/

bool	lf_check_nupi(long double x)
{
	t_lfloat ulf;

	ulf.x = x;
	if (ulf.y.exponent == 0b111111111111111 && ulf.y.mantissa != 1ULL << 63)
		return (true);
	if (ulf.y.exponent != 0 && !(ulf.y.mantissa & (1ULL << 63)))
		return (true);
	return (false);
}
