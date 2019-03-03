/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_concept1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 01:57:50 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/03 22:18:54 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int64_t		detectnull(int64_t s)
{
	return ((s - 0x0101010101010101) & ~s & 0x8080808080808080);
}

size_t	ft_strlen_v3(char *s)
{
	char *str;

	str = s;

	while (*str && (int64_t)s % 8)
	while (!(detectnull(*(long long *)str)))
	{
		str += sizeof(long long);
	}
	while (*str)
	{
		str++;
	}
	return (str - s);
}
