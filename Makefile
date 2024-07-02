# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 02:39:39 by greus-ro          #+#    #+#              #
#    Updated: 2024/07/02 22:34:37 by gabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET	= \033[0;39m
GRAY    = \033[0;90m
RED     = \033[0;91m
GREEN   = \033[0;92m
YELLOW  = \033[0;93m
BLUE    = \033[0;94m
MAGENTA = \033[0;95m
CYAN    = \033[0;96m
WHITE   = \033[0;97m

NAME		= libgnl.a
#BONUS		= get_next_line_bonus.o

INC_DIR	= ./inc
OBJ_DIR = ./obj
SRC_DIR	= ./src

CC				= cc
CFLAGS			= -Wall -Werror -Wextra 
DFLAGS			= -MMD -MP

ifndef GNL_BUFFER_SIZE
	PARAM_FLAGS		= -D BUFFER_SIZE=30
else
	PARAM_FLAGS		= -D BUFFER_SIZE=$${GNL_BUFFER_SIZE}
endif

ifdef CSANITIZE
	SANITIZE_FLAGS = -g -fsanitize=$${CSANITIZE}
endif

SRC_FILES		= 	get_next_line			\
					get_next_line_utils 

BONUS_SRC_FILES	=	get_next_line_bonus 		\
					get_next_line_utils_bonus 

SRC	=	$(addprefix ${SRC_DIR}/, $(addsuffix .c, ${SRC_FILES}))
OBJ =	$(addprefix ${OBJ_DIR}/, $(addsuffix .o, ${SRC_FILES}))
DEP	=	$(addprefix ${OBJ_DIR}/, $(addsuffix .d, ${SRC_FILES}))

BONUS_SRC	=	$(addprefix ${SRC_DIR}/, $(addsuffix .c, ${BONUS_SRC_FILES}))
BONUS_OBJ	=	$(addprefix ${OBJ_DIR}/, $(addsuffix .o, ${BONUS_SRC_FILES}))
BONUS_DEP	=	$(addprefix ${OBJ_DIR}/, $(addsuffix .d, ${BONUS_SRC_FILES}))

define compile
    printf "%b%-46b" "$(BLUE)compiling " "$(CYAN)$(@F)$(RESET)"; \
    $(1) > /dev/null; \
    RESULT=$$?; \
    if [ $$RESULT -ne 0 ]; then \
        printf "%b\n" "$(RED)[✗]$(RESET)"; \
    else  \
        printf "%b\n" "$(GREEN)[✓]$(RESET)"; \
    fi; \
    [ $$RESULT -eq 0 ]
endef

define link
	printf "%b%-48b" "$(YELLOW)linking " "$(CYAN)$(@F)$(RESET)"; \
    $(1) > /dev/null; \
    RESULT=$$?; \
    if [ $$RESULT -ne 0 ]; then \
        printf "%b\n" "$(RED)[✗]$(RESET)"; \
    else  \
        printf "%b\n" "$(GREEN)[✓]$(RESET)"; \
    fi; \
    [ $$RESULT -eq 0 ]
endef

all: ${NAME}

${NAME} : ${BONUS_OBJ}
	@$(call link, ar -rcs ${NAME} ${BONUS_OBJ})
	
${OBJ_DIR}/%.o : ${SRC_DIR}/%.c Makefile
	@mkdir -p ${OBJ_DIR}
	@$(call compile, ${CC} ${CFLAGS} ${DFLAGS} ${PARAM_FLAGS} ${SANITIZE_FLAGS} -I ${INC_DIR} -o $@ -c $< )

clean:
	rm -f ${OBJ_DIR}/*.o
	rm -f ${OBJ_DIR}/*.d

fclean: clean 
	rm -f ${NAME}

re: fclean all

norm:
	@norminette $(SRC_DIR) $(INC_DIR) | grep -v OK \
		|| echo "$(GREEN)Norminette: OK $(RST)"

-include ${BONUS_DEP}

.PHONY: all clean fclean re norm
