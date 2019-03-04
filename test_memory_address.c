/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:45:59 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/04 02:11:39 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

int   main(void)
{
	char *ptr = "Hello";
	int j = 0;
	int i = 0;
	int *pint = &j;

	printf("       \"Hello\" : %p\n", ptr);
	printf("  int64 : %#.16llx\n", (int64_t)ptr % 8);
	printf(" uint64 : %#.16llx\n", (uint64_t)ptr & 7);
	printf("uintptr : %#.16lx\n\n", (uintptr_t)ptr % 8);

	while (i < 3)
	{
		printf("       pint void deref : %p\n", &((void *)pint)[i]);
		printf("       pint int  deref : %p\n\n", &pint[i]);
		i++;
	}
	printf("\n\n");
	i = 0;
	while (i < 3)
	{
		printf("  pint void++ non deref: %p\n", (void *)pint);
		pint = (void *)pint + 1;
		i++;
	}
	printf("\n\n");
	i = 0;
	// while (1)
	{
		// printf("  pint++ void non deref: %d\n", *pint);
		// printf("  pint++ void non deref: %p\n", (void *)pint);
		// printf("%#.16lx\n", (uintptr_t)pint);
		// pint+=1000000000000000;
		// i++;
	}
  return (0);
}

/*
** On peut choper toutes les adresses ? Ou simplement l'adresse est un nombre
** qui boucle de 0 à 64 bits puis qui est validé par l'ordinateur ?
*/
