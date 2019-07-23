/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:34:32 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/30 19:55:08 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int					s;
	unsigned long long	nb;

	nb = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if ((s = (*str == '-') ? -1 : 1) == -1 || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		nb = nb * 10 - '0' + (unsigned long long)*str++;
	if (nb > 9223372036854775807ULL && s == 1)
		return (-1);
	if (nb > 9223372036854775808ULL && s == -1)
		return (0);
	return ((int)nb * s);
}

/*
** ATTENTION INITIALISER SES VARIABLES SINON INDETER, ET BOOM
*/
