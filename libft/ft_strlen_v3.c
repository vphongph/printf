/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_v3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 01:57:50 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/04 14:53:07 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

/*
** stdint.h can be ok too for the different types of int
** but don't have the size_t, for the latter you can use stdlib.h or string.h
*/

static int64_t	detectnull(int64_t s)
{
	return ((s - 0x0101010101010101) & ~s & 0x8080808080808080);
}

int				ft_strlen_v3(char *s)
{
	char *str;

	str = s;
	if (!s && (write(2, RED"\astrlen v3 -> ∅ pointer\n"RESET, 45)))
		return (-1);
	while (*str && (uintptr_t)str & 7)
		str++;
	while (!(detectnull(*(int64_t *)str)))
		str += sizeof(int64_t);
	while (*str)
		str++;
	return (str - s);
}
