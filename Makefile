# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/24 21:12:59 by vphongph          #+#    #+#              #
#    Updated: 2019/03/28 13:05:33 by vphongph         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#___________________________________COLORS_____________________________________#

blink		:= 	"\033[5:m"
blue		:= 	"\033[38;5;26m"
purple_dark	:= 	"\033[38;5;62m"
purple		:= 	"\033[38;5;98m"
purple_coa	:= 	"\033[38;5;93m"
green		:= 	"\033[38;5;70m"
green_coa	:= 	"\033[38;5;47m"
green_dark	:= 	"\033[38;5;28m"
red			:= 	"\033[38;5;196m"
red_dark	:= 	"\033[38;5;88m"
grey		:=	"\033[38;5;242m"
yellow		:= 	"\033[38;5;178m"
reset		:= 	"\033[0m"

#__________________________________CONSTANTS___________________________________#

NAME			:=	printf

CC				:=	gcc

ifeq ($(DEBUG), yes)
	CFLAGS		:=	-Wall -Wextra -Werror -g3 -fsanitize=address,undefined
else
	CFLAGS		:=	-Wall -Wextra -Werror -MMD
endif

SRC_NAMES		:=	ft_printf.c		\
					ft_pow_int.c		\
					main.c

SRC_PATH		:=

SRCS			:=	$(addprefix $(SRC_PATH), $(SRC_NAMES))

OBJ_NAMES		:=	$(SRC_NAMES:.c=.o)

OBJ_PATH		:=	objects/

OBJS			:=	$(addprefix $(OBJ_PATH), $(OBJ_NAMES))

DEP_NAMES		:=	$(SRC_NAMES:.c=.d)

DEP_PATH		:=	$(OBJ_PATH)

DEPS			:=	$(addprefix $(DEP_PATH), $(DEP_NAMES))

LIBS			:=	libft/libft.a	\

RUN_ARGS		:=	$(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))

RULE_SENT		:= 	$(firstword $(MAKECMDGOALS))

.DEFAULT_GOAL	:=  all

#_________________________________VARIABLES____________________________________#

libraries		=	$(shell make -q -s -C $(1) || echo 'FORCE')

#________________________________LIBS_RULES____________________________________#

.SECONDEXPANSION:

ifneq ($(LIBS), )
ifneq ($(RULE_SENT), re)
$(LIBS)			:	$$(strip $$(call libraries,$ $$(@D)))
		@make -C $(@D)
endif
endif

#__________________________________RULES_______________________________________#


.PHONY			:	all clean fclean re relibs FORCE run


all				:	$(NAME)
ifeq ($(DEBUG), yes)
				@echo $(red)$(blink)" DEBUG"$(reset) $(yellow)"MODE $(NAME)"\
				$(grey)"don't forget debug mode for libs"$(reset)
endif

$(NAME)			:	$(LIBS) $(OBJS)
				@$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)
				@echo $(green_dark)" Compiling" $(grey)"libs and objects" $(green)"-> $@"$(reset)
ifneq ($(DEBUG), yes)
				@echo $(yellow)" NORMAL MODE $(NAME)"$(reset)
endif
	@echo $(blue)"                           P r i n t f - C i t y"
	@echo "          -------------------------------------------------------"
	@echo ""
	@echo "                  ________            _______ "
	@echo "         /\ \ \ \/_______/     ______/\      \  /\ \/ /\ \/ /\  \_____________ "
	@printf "        /\ \ \ \/______ /     /\    /:"
	@printf "\\"
	@echo "\      \ ::\  /::\  /::\ /____  ____ __ "
	@printf "       /\ \ \ \/_______/     /:"
	@printf "\\"
	@printf "\  /:\:"
	@printf "\\"
	@echo "\______\::/  \::/  \::///   / /   // "
	@echo "      /\ \ \ \/_______/    _/____\/:\:\:/_____ / / /\ \/ /\ \///___/ /___//___ "
	@printf "_____/___ \ \/_______/    /\::::::"
	@printf "\\"
	@echo "\:\:/_____ / \ /::\  /::\ /____  ____  ____ "
	@printf "         \ \/_______/    /:"
	@printf "\\"
	@printf "\::::::"
	@printf "\\"
	@printf "\:/_____ /   "
	@printf "\\"
	@echo "\::/  \::///   / /   / /   / "
	@printf "          \/_______/    /:\:"
	@printf "\\"
	@printf "\______\/______/_____"
	@printf "\\"
	@echo "\/ /\ \///___/ /___/ /_____ "
	@echo "\          \______/    /:\:\:/_____:/\      \ ___ /  /::\ /____  ____  _/\:::: "
	@printf "\\"
	@printf "\__________\____/    /:\:\:/_____:/:"
	@printf "\\"
	@echo "\      \__ /_______/____/_/___/_ /  \::: "
	@printf "//__________/___/   _/____:/_____:/:\:"
	@printf "\\"
	@echo "\______\ /                     /\  /\:: "
	@echo "///\          \/   /\ .----.\___:/:\:\:/_____ // \ "$(green_coa)"vphongph"$(blue)"          /  \/  \: "
	@printf "///"
	@printf "\\"
	@printf "\          \  /::"
	@printf "\\"
	@printf "\ \_"
	@printf "\\"
	@printf " \\"
	@echo "\_:/:\:\:/_____ //:\ \ "$(purple_coa)"glamit"$(blue)"          /\  /\  /\ "
	@printf "//:/"
	@printf "\\"
	@printf "\          \//\::"
	@printf "\\"
	@printf "\ \ "
	@printf "\\"
	@printf " \\"
	@echo "\/:\:\:/_____ //:::\ \ "$(green_coa)"alamit"$(blue)"        /  \/  \/+/ "
	@printf "/:/:/"
	@printf "\\"
	@printf "\_________/:\/:::"
	@printf "\\"
	@printf "\`----' "
	@printf "\\"
	@echo "\:\:/_____ //o:/\:\ \_____________/\  /\  / / "
	@printf ":/:/://________//\::/\::\_______"
	@printf "\\"
	@echo "\:/_____ ///\_\ \:\/____________/  \/  \/+/\ "
	@printf "/:/:///_/_/_/_/:\/::\ \:/__  __ /:/_____ ///\//"
	@printf "\\"
	@echo "\/:/ _____  ____/\  /\  / /  \ "
	@echo ":/:///_/_/_/_//\::/\:\///_/ /_//:/______/_/ :~\/::/ /____/ /___/  \/  \/+/\  / "
	@printf "/:///_/_/_/_/:\/::\ \:/__  __ /:/____/\  / "
	@printf "\\"
	@echo "\:\/:/ _____  ____/\  /\  / /  \/ "
	@printf ":///_/_/_/_//\::/\:\///_/ /_//:/____/\:\____"
	@printf "\\"
	@echo "\::/ /____/ /___/  \/  \/+/\  /\ "
	@printf "///_/_/_/_/:\/::\ \:/__  __ /:/____/\:\/____/"
	@printf "\\"
	@echo "\/____________/\  /\  / /  \/  \ "
	@echo "//_/_/_/_//\::/\:\///_/ /_//::::::/\:\/____/  /----/----/--/  \/  \/+/\  /\  / "
	@echo "/_/_/_/_/:\/::\ \:/__  __ /\:::::/\:\/____/ \/____/____/__/\  /\  / /  \/  \/_ "
	@echo "_/_/_/_//\::/\:\///_/ /_//\:\::::\:\/____/ \_____________/  \/  \/+/\  /\  / "
	@echo "/_/_/_/:\/::\ \:/__  __ /\:\:\::::\/____/   \ _ _ _ _ _ /\  /\  / /  \/  \/___ "
	@echo "_/_/_//\::/\:\///_/ /_//\:\:\:\              \_________/  \/  \/+/\  /\  /   / "
	@echo "/_/_/:\/::\ \:/__  __ /\:\:\:\:\______________\       /\  /\  / /  \/  \/___/_ "
	@echo "_/_//\::/\:\///_/ /_//::\:\:\:\/______________/      /  \/  \/+/\  /\  /   / "
	@echo "/_/:\/::\ \:/__  __ /::::\:\:\/______________/\     /\  /\  / /  \/  \/___/___ "
	@echo "_//\::/\:\///_/ /_//:\::::\:\/______________/  \   /  \/  \/+/\  /\  /   /   / "
	@echo "/:\/::\ \:/__  __ /:\:\::::\/______________/    \ /\  /\  / /  \/  \/___/___/ "
	@printf "/\::/\:\///_/ /_//:\:\:\                         \  \/"
	@printf "\\"
	@printf "\\"
	@printf "\\"
	@echo "/+/\  /\  /   /   /+/ "
	@printf "\/::\ \:/__  __ /:\:\:\:\_________________________\ ///"
	@printf "\\"
	@printf "\\"
	@printf "\\"
	@echo "/  \/  \/___/___/ /_ "
	@printf "::/\:\///_/ /_//:\:\:\:\/_________________________////::"
	@printf "\\"
	@printf "\\"
	@printf "\\"
	@echo "  /\  /   /   /+/ "
	@printf "::\ \:/__  __ /:\:\:\:\/_________________________/:\/____"
	@printf "\\"
	@printf "\\"
	@printf "\\"
	@echo "/  \/___/___/ /___ "
	@echo "/\:\///_/ /_//:\:\:\:\/_________________________/:::\    /\/\  /   /   /+/   / "
	@echo "\ \:/__  __ /:\:\:\:\/_________________________/:::::\  ///  \/___/___/ /___/_ "
	@echo ":\///_/ /_//:\:\:\:\/_________________________/:\:::::\///\  /   /  __________ "
	@echo "\:/__  __ /:\:\:\:\/_________________________/:::\:::::\/  \/___/__/\ "
	@echo "///_/ /_//:\:\:\:\/_________________________/:\:::\:::::\  /   /  /::\ "
	@echo "/__  __ /\::\:\:\/_________________________/_____::\:::::\/___/__/:/\:\ "
	@echo "/_/ /_//::\::\:\/_____________________/\/_/_/_/_/\  \           /::\ \:\ "
	@printf "_  __ /:\::\:8\/_____________________/\/\   /\_"
	@printf "\\"
	@echo "\/\  \ 8       /:/\:\ \:\ "
	@printf "/ /_//\     \|______________________//"
	@printf "\\"
	@printf "\/\::\/__"
	@printf "\\"
	@echo "\/\  \|______/::\ \:\ \:\ "
	@echo " __ /  \  \                        /:\/:\/\_______\/\        /:/\:\ \:\/::\ "
	@printf "/_//    8      -8  --  --  --  -- //\::/"
	@printf "\\"
	@echo "\/_/_/_/_/_/ --  --/::\ \:\ \::/\:\ "
	@echo "_ /     |\  \   |________________/:\/::\///__/ /__//_______/:/\:\ \:\/::\ \:\ "
	@echo "__________\     \               //\::/\:/___  ___ /       /::\ \:\ \::/\:\ \:\ "
	@printf "::::::::::"
	@printf "\\"
	@echo "\  \  \             /:\/::\///__/ /__//       /:/\:\ \:\/::\ \:\ \: "$(reset)


$(OBJ_PATH)%.o	:	$(SRC_PATH)%.c
ifneq ($(RULE_SENT), re)
				@echo $(green)" NEW" $?
endif
				@mkdir -p $(OBJ_PATH) 2>/dev/null || true
				@$(CC) $(CFLAGS) -c $< -o $@
				@echo $(green_dark)"  Compiling" $(grey)$< $(green_dark)\
				"->" $(grey)"$@"$(reset)


clean			:
ifeq ($(RULE_SENT), clean)
				@$(foreach varToGen, $(LIBS), make clean -C $(dir $(varToGen));)
endif
				@/bin/rm -f $(OBJS)
				@/bin/rm -f $(DEPS)
				@rmdir $(OBJ_PATH) 2>/dev/null || true
				@echo $(red_dark)" Removing objects from" $(grey)$(NAME)$(reset)


fclean			:	clean
ifeq ($(RULE_SENT), fclean)
				@$(foreach varToGen, $(LIBS), make fclean -C $(dir $(varToGen));)
endif
				@/bin/rm -f $(NAME)
	 			@echo $(red_dark)" Removing binary" $(grey)$(NAME)$(reset)


re				:	relibs fclean all


relibs			:
				@$(foreach varToGen, $(LIBS), make re -C $(dir $(varToGen));)


FORCE			:


ifeq ($(RULE_SENT), run)
ifndef VERBOSE
.SILENT			:
endif
endif


run				:	all
				./$(NAME) $(RUN_ARGS)

-include $(DEPS)
