/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_glob_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:45:59 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/04 17:10:21 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

void	*address_get_set(void *address_to_save);

void	*format_set_get(void *format)
{
	static void 	*ptr = NULL;

	if (format)
		ptr = format;
	return (ptr);
}

void leaks(void)
{
	char *c = malloc(100);
	(void)c;
	// c++;
	free(c);
	c = NULL;
}


void 	other(void)
{
	// char *c2 = format_set_get(NULL);
	char *c2 = address_get_set(NULL);
	printf("c2 : %s\n", c2);
	c2[0] = 'A';
	c2[1] = 'H';

}

int		main(void)
{
	char init = 'a';
	char *c1 = &init;

	c1[0] = 'o';
	c1[1] = 'k';
	c1[2] = 0;

	printf("c1 : %s\n", c1);

	// format_set_get(c1);
	address_get_set(c1);

	other();

	c1[0] = 'k';
	c1[1] = 'o';

	other();

	printf("c1 : %s\n", c1);

	leaks();

	sleep(1);

	return (0);
}
