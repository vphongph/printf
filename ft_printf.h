/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:11:36 by vphongph          #+#    #+#             */
/*   Updated: 2019/04/03 02:26:12 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <i386/endian.h>
# if __DARWIN_BYTE_ORDER == __DARWIN_LITTLE_ENDIAN
#  include "libft/libft.h"
#  include <stdlib.h>

typedef struct	s_format
{
	int fieldwidth;
	int precision;
	int options;
	int	type;
}				t_format;

typedef struct s_big_int
{
	const __uint128_t uint128_max;
}				t_big_int;

# endif
#endif
