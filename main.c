/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:45:59 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/03 23:58:16 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <stdint.h>

int   main(void)
{
	char *ptr = "Hello";

	printf("       \"Hello\" : %p\n", ptr);
	printf("  int64 : %#.16llx\n", (int64_t)ptr % 8);
	printf(" uint64 : %#.16llx\n", (uint64_t)ptr & 7);
	printf("uintptr : %#.16lx\n\n", (uintptr_t)ptr % 8);

  return (0);
}
