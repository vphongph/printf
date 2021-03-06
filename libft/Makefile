# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/24 21:12:59 by vphongph          #+#    #+#              #
#    Updated: 2019/04/18 20:02:33 by vphongph         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

blink			= 	"\033[5:m"
purple_dark		= 	"\033[38;5;62m"
purple			= 	"\033[38;5;98m"
green			= 	"\033[38;5;70m"
green_dark		= 	"\033[38;5;28m"
red				= 	"\033[38;5;196m"
red_dark		= 	"\033[38;5;88m"
grey			=	"\033[38;5;242m"
yellow			= 	"\033[38;5;178m"
reset			= 	"\033[0m"

NAME		=	libft.a

CC			=	gcc

ifeq ($(DEBUG), yes)
	CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address,undefined
else ifeq ($(DEBUG), all)
	CFLAGS	=	-g3 -Weverything
else ifeq ($(DEBUG), san)
	CFLAGS	=	-Wall -Wextra -g3 -fsanitize=address,undefined
else
	CFLAGS	=	-Wall -Wextra -Werror
endif

SRCS		=	ft_memalloc.c		\
				ft_memdel.c			\
				ft_memjoin.c		\
				ft_memjoinfree_l.c	\
				ft_memcpy_v2.c		\
				ft_strlen_v2.c		\
				ft_putstr_fd_v2.c	\
				ft_putstr_v2.c		\
				ft_bzero_v2.c		\
				ft_strsub_v2.c		\
				ft_dlstnew.c		\
				ft_dlstdelone.c		\
				ft_dlstadd.c		\
				ft_atoi.c			\
				ft_memset.c			\
				ft_strlen_v3.c		\
				ft_itoa.c			\
				mth_pow_int.c		\
				ft_printbin.c		\
				ft_putnbr_base.c	\
				detectchar.c		\
				lf_get_exponent.c	\
				lf_set_exponent.c	\
				lf_set_nan_inf.c	\
				lf_check_nupi.c		\
				lf_remove_decimal.c	\
				ft_putnnbr_base.c	


OBJS		=	$(SRCS:.c=.o)

HDRS		=	libft.h


.PHONY	:	all clean fclean re


all	:	$(NAME)


$(NAME)	:	$(OBJS)
		@ar r $(NAME) $(OBJS) 2>/dev/null
		@echo $(purple_dark)" Making lib" $(purple)"-> $@"$(reset)
		@ranlib $(NAME)
		@echo $(purple_dark)" Indexing lib"$(reset)
ifeq ($(DEBUG), yes)
		@echo " $(CFLAGS)"$(reset)
		@echo $(red)$(blink)" DEBUG"$(reset) $(yellow)"MODE $(NAME)"$(reset)
else
		@echo " $(CFLAGS)"$(reset)
		@echo $(yellow)" NORMAL MODE $(NAME)"$(reset)
endif


%.o		:	%.c $(HDRS)
ifneq ($(firstword $(MAKECMDGOALS)), re)
		@echo $(purple)" NEW" $?
endif
		@$(CC) $(CFLAGS) -c $< -o $@
		@echo $(purple_dark)"  compiling" $(grey)$< $(purple_dark)"->" $(grey)$@$(reset)


clean	:
		@/bin/rm -f $(OBJS)
		@echo $(red_dark)" Removing objects from" $(grey)$(NAME)$(reset)


fclean	:	clean
		@/bin/rm -f $(NAME)
		@echo $(red_dark)" Removing lib" $(grey)$(NAME)$(reset)


re		:	fclean all
