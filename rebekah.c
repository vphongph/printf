/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebekah.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 22:03:08 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/10 22:25:05 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	char s[100];
	int i = 0;

	puts("Est-ce que tu veux boire ?\n");

	scanf("%s", s);

	if (s[0] == 'o' && s[1] == 'u'&& s[2] =='i')
		puts("Quel âge as-tu ?\n");
	else
	{
		puts("Nique ta mère enculée !\n");
		return (0);
	}

	scanf("%s", s);
	i = ft_atoi(s);

	if (i < 18)
		puts("Tu peux pas boire\n");
	if (i >= 18)
		puts("Ben euh nana attends t'es chiant\n");

	return (0);
}
