/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:11:36 by vphongph          #+#    #+#             */
/*   Updated: 2019/06/30 07:05:41 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <i386/endian.h>
# if __DARWIN_BYTE_ORDER == __DARWIN_LITTLE_ENDIAN
#  include "libft/libft.h"
#  include <stdlib.h>


const extern __uint128_t g_128max;

/*
**  340282366920938463463374607431768211455
** -170141183460469231731687303715884105728
**  170141183460469231731687303715884105727
*/


#  define TEST_MAX ((__uint128_t)ULLONG_MAX * 0x1000000000000000 * 0x10 + ULLONG_MAX)

#  define UINT128_MAX ((__uint128_t)0xFFFFFFFFFFFFFFFF * 0x1000000000000000 \
	* 0x10 + 0xFFFFFFFFFFFFFFFF)
#  define INT128_MIN ((__uint128_t)0x8000000000000000 * 0x1000000000000000 * 0x10)
#  define INT128_MAX (INT128_MIN - 1)
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


# define BIG_INT_DIGIT 32
# define BIG_INT_CARRY ((__uint128_t)10000000000000000000ULL * 10000000000000)
# define BIG_INT_MAX (BIG_INT_CARRY - 1)
# define BIG_INT_FACTOR (UINT128_MAX / BIG_INT_CARRY)
# define BIG_INT_TAB 360
# define BIG_INT_POW2 21
# define BIG_INT_POW2_RES 2097152
# define BIG_INT_POW5 9
# define BIG_INT_POW5_RES 1953125
# define BIG_INT_EXPO 16445

typedef struct	s_format
{
	int fieldwidth;
	int precision;
	int options;
	int	type;
}				t_format;

typedef struct	s_big_int
{
	const __uint128_t uint128_max;
}				t_big_int;

extern const 	__uint128_t uint128_max;

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









// #define BIG_INT_DIGIT 37
// #define BIG_INT_CARRY ((__uint128_t)10000000000000000000ULL * 1000000000000000000)
// #define BIG_INT_MAX (BIG_INT_CARRY - 1)
// #define BIG_INT_FACTOR (UINT128_MAX / BIG_INT_CARRY)
// #define BIG_INT_TAB 312
// #define BIG_INT_POW2 5
// #define BIG_INT_POW2_RES 32
// #define BIG_INT_POW5 2
// #define BIG_INT_POW5_RES 25
// #define BIG_INT_EXPO 16445


// #define BIG_INT_DIGIT 36
// #define BIG_INT_CARRY ((__uint128_t)10000000000000000000ULL * 100000000000000000)
// #define BIG_INT_MAX (BIG_INT_CARRY - 1)
// #define BIG_INT_FACTOR (UINT128_MAX / BIG_INT_CARRY)
// #define BIG_INT_TAB 320
// #define BIG_INT_POW2 8
// #define BIG_INT_POW2_RES 256
// #define BIG_INT_POW5 3
// #define BIG_INT_POW5_RES 125
// #define BIG_INT_EXPO 16445


// #define BIG_INT_DIGIT 35
// #define BIG_INT_CARRY ((__uint128_t)10000000000000000000ULL * 10000000000000000)
// #define BIG_INT_MAX (BIG_INT_CARRY - 1)
// #define BIG_INT_FACTOR (UINT128_MAX / BIG_INT_CARRY)
// #define BIG_INT_TAB 329
// #define BIG_INT_POW2 11
// #define BIG_INT_POW2_RES 2048
// #define BIG_INT_POW5 5
// #define BIG_INT_POW5_RES 3125
// #define BIG_INT_EXPO 16445


// #define BIG_INT_DIGIT 34
// #define BIG_INT_CARRY ((__uint128_t)10000000000000000000ULL * 1000000000000000)
// #define BIG_INT_MAX (BIG_INT_CARRY - 1)
// #define BIG_INT_FACTOR (UINT128_MAX / BIG_INT_CARRY)
// #define BIG_INT_TAB 339
// #define BIG_INT_POW2 15
// #define BIG_INT_POW2_RES 32768
// #define BIG_INT_POW5 6
// #define BIG_INT_POW5_RES 15625
// #define BIG_INT_EXPO 16445


// #define BIG_INT_DIGIT 33
// #define BIG_INT_CARRY ((__uint128_t)10000000000000000000ULL * 100000000000000)
// #define BIG_INT_MAX (BIG_INT_CARRY - 1)
// #define BIG_INT_FACTOR (UINT128_MAX / BIG_INT_CARRY)
// #define BIG_INT_TAB 349
// #define BIG_INT_POW2 18
// #define BIG_INT_POW2_RES 262144
// #define BIG_INT_POW5 7
// #define BIG_INT_POW5_RES 78125
// #define BIG_INT_EXPO 16445

// #define BIG_INT_DIGIT 31
// #define BIG_INT_CARRY ((__uint128_t)10000000000000000000ULL * 1000000000000)
// #define BIG_INT_MAX (BIG_INT_CARRY - 1)
// #define BIG_INT_FACTOR (UINT128_MAX / BIG_INT_CARRY)
// #define BIG_INT_TAB 372
// #define BIG_INT_POW2 25
// #define BIG_INT_POW2_RES 33554432
// #define BIG_INT_POW5 10
// #define BIG_INT_POW5_RES 9765625
// #define BIG_INT_EXPO 16445


// #define BIG_INT_DIGIT 20
// #define BIG_INT_CARRY ((__uint128_t)10000000000000000000ULL * 10)
// #define BIG_INT_MAX (BIG_INT_CARRY - 1)
// #define BIG_INT_FACTOR (UINT128_MAX / BIG_INT_CARRY)
// #define BIG_INT_TAB 576
// #define BIG_INT_POW2 61
// #define BIG_INT_POW2_RES 2305843009213693952
// #define BIG_INT_POW5 26
// #define BIG_INT_POW5_RES 1490116119384765625
// #define BIG_INT_EXPO 16445


# endif
#endif
