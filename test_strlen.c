/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:45:59 by vphongph          #+#    #+#             */
/*   Updated: 2019/04/04 03:32:39 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include <string.h>

size_t	ft_strlen(const char *s);
int		ft_strlen_v3(char *s);
void	*ft_memset(void *b, int c, size_t len);

// int		ft_strlen_v2(char *s);

// int 	ft_strlen(char *s)
// {
	// char *str = s;
	// while (*str)
		// str++;
	// return (str -s);
// }

int		main(void)
{
	int i = 0;
	char s[4095];
	ft_memset(s, '*', 4094);
	s[4094] = 0;

	// char *s = NULL;

	while (i < 1000000)
	{
		ft_strlen(s);
		// ft_strlen_v2(s);
		// ft_strlen_v3(s);
		// strlen(s);
		i++;
	}

	// printf("ft_strlen_v2 : %d\n", ft_strlen_v2(s));
	// printf("ft_strlen_v3 : %d\n", ft_strlen_v3(s));
	// printf("strlen       : %lu\n", strlen(s));

	return (0);
}
