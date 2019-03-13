/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 01:37:46 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/13 20:52:39 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void		ft_bzero_v2(void *s, size_t n);
void		ft_bzero_v3(void *s, int64_t n);



int 	main()
{
	int tab[1024];
	int i = 0;

	tab[500] = '4';
	tab[1023] = '8';



	while (i < 10000000)
	{
		// ft_bzero_v3(tab, 4092);
		ft_bzero_v2(tab, 4092);
		i++;
	}

	write(1, tab, 4096);
	write(1, "\n", 1);

	return (0);
}
