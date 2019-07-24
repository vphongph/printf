/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:11:36 by vphongph          #+#    #+#             */
/*   Updated: 2019/07/24 00:27:53 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <i386/endian.h>
# if __DARWIN_BYTE_ORDER == __DARWIN_LITTLE_ENDIAN
#  include "libft.h"
#  include <stdlib.h>

/*
**  340282366920938463463374607431768211455
** -170141183460469231731687303715884105728
**  170141183460469231731687303715884105727
*/


#  define UINT128_MAX ((__uint128_t)0xFFFFFFFFFFFFFFFF * 0x1000000000000000 * 0x10 + 0xFFFFFFFFFFFFFFFF)
#  define DISTRIB_2_TO_8 ((__uint128_t)0x0001000100010001 * 0x1000000000000 * 0x10000 + 0x0001000100010001)
#  define MANTISSA_TAB 64

/*
** ____BIG_INT_DIGIT____
** Nb de chiffres max dans un big int
** ____BIG_INT_CARRY____
** Valeur à partir de laquelle on est dans la retenue, nb de 0 de CARRY = DIGIT
** + DIGIT petit + CARRY grand
** ____BIG_INT_TAB____
** Taille min du tableau pour contenir le plus petit float sans les leading 0
** Soit => 11 514 chiffres / DIGIT (+ 1, si modolo != 0)
** ____BIG_INT_FACTOR____
** Facteur max sans int overflow, + CARRY grand + FACTOR grand
** -> UINT128_MAX / CARRY (== 34028236)
** ____BIG_INT_POW2____
** Puissance de 2 max >= FACTOR
** ____ BIG_INT_POW5____
** Puissance de 5 max >= FACTOR
*/

#  define BIG_INT_DIGIT 32
#  define BIG_INT_CARRY ((__uint128_t)10000000000000000000ULL * 10000000000000)
#  define BIG_INT_FACTOR (UINT128_MAX / BIG_INT_CARRY)
#  define BIG_INT_TAB 360
#  define BIG_INT_POW2 21
#  define BIG_INT_POW2_RES 2097152
#  define BIG_INT_POW5 9
#  define BIG_INT_POW5_RES 1953125
#  define BIG_INT_EXPO 16445

typedef struct		s_flags
{
	int				fd;
	unsigned int	f_size;
	int				ret;
	int				minus;
	int				plus;
	int				zero;
	int				blank;
	int				htag;
	int				precision;
	int				padding;
	int				width_len;
	char			conv;
	t_length		l;
}					t_flags;

struct							s_printf_float
{
	__uint128_t	tab128_int[BIG_INT_TAB];
	__uint128_t	tab128_dec[BIG_INT_TAB];
	long double	value;
	int64_t		sm_mantissa;
	int64_t		nb_digits_int;
	int64_t		nb_digits_dec;
	int64_t		nb_leading;
	int64_t		location;
	int64_t		digits_to_print;
	int64_t		leading_to_print;
	int64_t		trailing_to_print;
	int64_t		char_to_print;
	uint16_t	exponent;
	bool		neg;
	int 		exception;
	// int16_t tab_expo[MANTISSA_TAB + 1];
	__uint128_t	padding : 104;
};
typedef struct s_printf_float	t_printf_float;


int8_t			big_int_x(__uint128_t *tab_nb, uint16_t tab_size, uint64_t fact);
int8_t			big_int_pow_of_2(__uint128_t *tab, uint16_t tab_s, int16_t expo);
int8_t			big_int_add(__uint128_t *tab1, __uint128_t *tab2, uint16_t tab_s);
int16_t			big_int_print(__uint128_t *tab_nb, uint16_t tab_size);
int16_t			big_int_count(__uint128_t *tab_nb, uint16_t tab_size);
int16_t			lf_get_mantissa_pow(int16_t *tab_expo, long double lf);
int8_t			big_int_calc_int(__uint128_t *tab_nb, uint16_t tab_s, int16_t *tab_expo);
int8_t			big_int_calc_dec(__uint128_t *tab_nb, uint16_t tab_s, int16_t *tab_expo);
int16_t			big_int_n_print(__uint128_t *tab_nb, uint16_t tab_s, int16_t n);
int8_t			big_int_add_one(__uint128_t *tab_nb, int16_t index, __uint128_t one);
int16_t			big_int_round(__uint128_t *tab_nb, int64_t location);
int16_t			big_int_rm_1st_dec(__uint128_t *tab_nb, int16_t tab_size);
// int16_t			compute_float(t_printf_meta *smeta, t_printf_float *sf);

# endif
#endif
