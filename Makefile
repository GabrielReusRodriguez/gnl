# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 02:39:39 by greus-ro          #+#    #+#              #
#    Updated: 2024/02/01 23:40:03 by greus-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= get_next_line.o
BONUS		= get_next_line_bonus.o

INC_DIR	= ./inc
BIN_DIR = ./bin
SRC_DIR	= ./src

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -MMD -MP
DFLAGS		= -D BUFFER_SIZE=30

SRC_FILES	= 	get_next_line.c \
				get_next_line_utils.c 
				
OBJ_FILES	= $(SRC_FILES:%.c=${BIN_DIR}/%.o)
DEP_FILES	= $(SRC_FILES:%.c=${BIN_DIR}/%.d)
SRC = $(addprefix ${SRC_DIR}, ${SRC_FILES})

BONUS_SRC_FILES	=	get_next_line_bonus.c \
					get_next_line_utils_bonus.c 

BONUS_OBJ_FILES	= $(BONUS_SRC_FILES:%.c=${BIN_DIR}/%.o)
BONUS_DEP_FILES	= $(BONUS_SRC_FILES:%.c=${BIN_DIR}/%.d)
SRC_BONUS = $(addprefix ${SRC_DIR}, ${BONUS_SRC_FILES})

#all: ${NAME}
all: ${OBJ_FILES}

#${NAME}: ${OBJ_FILES}
#	${CC} ${CFLAGS} -o ${NAME} $^

bonus: 	${BONUS}
		touch bonus

${BONUS}: ${BONUS_OBJ_FILES}
	${CC} ${CFLAGS} -o ${BONUS} $^

·{BIN_DIR}:
	mkdir -p ${BIN_DIR}
	
${BIN_DIR}/%.o : ${SRC_DIR}/%.c ${BIN_DIR} Makefile
	${CC} ${CFLAGS} ${DFLAGS} -I ${INC_DIR} -o $@ -c $<

clean:
	rm -f ${BIN_DIR}/*

fclean: clean 
	rm -f ./*.out

re: fclean all

-include ${DEP_FILES} ${BONUS_DEP_FILES}

.PHONY: all clean fclean re
