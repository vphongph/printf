/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:11:39 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/05 15:32:38 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int		ft_printf(const char *restrict format, ...)
{
	va_list alice;
	va_start(alice, format);

	printf("%.100f\n", va_arg(alice, double));

	return (0);
}
