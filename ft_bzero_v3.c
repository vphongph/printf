/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_v3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 18:34:10 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/11 03:11:50 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>

/*
** Possible aussi avec tableau[0] pour init
** La déclaration est donc la suivante:
** Quand on déclare partiellement la struc, tout le reste est à 0.
** Possible de déclarer en ligne car c'est une constante
** On déclare un tableau vide :
** const t_64speed		speed64 = {.init = 0};
** const t_512speed	speed512 = {.init = 0};
**
** Choix de la solution ci-dessus pour la norminette.
** Sinon "may not compile or is invalid for some reasons." à tort.
*/

void		ft_bzero_v3(void *s, size_t n)
{
	if (!s)
	{
		if (ft_putstr_fd_v2(RED"\abzero v2 -> ∅ pointer\n"RESET, 2) == -1)
			write(2, RED"\abzero v2 -> ∅ pointer & putstr fd v2 ∅\n"RESET, 63);
		return ;
	}
	while (n >> 4)
	{
		*(__int128 *)s = 0;
		s += 16;
		n -= 16;
	}
	while (n >> 3)
	{
		*(long long *)s = 0;
		s += 8;
		n -= 8;
	}
	while (n)
	{
		*(char *)s = 0;
		s++;
		n--;
	}
}