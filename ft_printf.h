/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:11:36 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/19 20:06:53 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# if __DARWIN_BYTE_ORDER == __DARWIN_LITTLE_ENDIAN
#include "libft/libft.h"
#  include <stdlib.h>

typedef struct	s_format
{
	int fieldwidth;
	int precision;
	int options;
	int	type;
}				t_format;

# endif
#endif
