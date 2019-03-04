/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:11:39 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/04 20:15:26 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int		ft_printf(const char *restrict format, ...)
{
	va_list alice;
	va_start(alice, format);

	int i = 0;

	alice = alice + 1;

	while (i < 10)
	{
		write(1, alice, 1);
		i++;
	}

	// printf ("%d\n", va_arg(alice, int));

	return (0);
}
