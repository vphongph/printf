/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modulo_lf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 12:47:30 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/17 12:55:45 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long double	ft_modulo_lf(long double x, long double y)
{
	long double result;
	long double remainder;

	result = x / y;
	remainder = x - result * y;
	return (remainder);
}
