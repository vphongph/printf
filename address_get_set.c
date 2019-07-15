/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address_get_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:03:58 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/05 22:01:45 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Signleton ?
*/

#include "libft.h"

void	*address_get_set(void *address_to_save)
{
	static void *address_saved = NULL;

	if (address_to_save)
		address_saved = address_to_save;
	return (address_saved);
}
