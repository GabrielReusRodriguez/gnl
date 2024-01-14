# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 02:39:39 by greus-ro          #+#    #+#              #
#    Updated: 2024/01/13 02:41:03 by greus-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= get_next_line.out
BONUS		= get_next_line_bonus.out

INC_FOLDER	= .
BIN_FOLDER  = ./bin

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -ggdb3 -MMD -MP
DFLAGS		= -D BUFFER_SIZE=30

SRC_FILES	= get_next_line.c get_next_line_utils.c main.c
OBJ_FILES	= $(SRC_FILES:%.c=${BIN_FOLDER}/%.o)

BONUS_SRC_FILES	=	get_next_line_bonus.c 		\
					get_next_line_utils.c 		\
					get_next_line_utils_bonus.c \
					main_bonus.c
BONUS_OBJ_FILES	= $(BONUS_SRC_FILES:%.c=${BIN_FOLDER}/%.o)


all: ${NAME}

${NAME}: ${OBJ_FILES}
	${CC} ${CFLAGS} -o ${NAME} $^

bonus: ${BONUS}

${BONUS}: ${BONUS_OBJ_FILES}
	${CC} ${CFLAGS} -o ${BONUS} $^

${BIN_FOLDER}/%.o:%.c
	mkdir -p ${BIN_FOLDER}
	${CC} ${CFLAGS} ${DFLAGS} -I ${INC_FOLDER} -o $@ -c $^

clean:
	rm -f ${BIN_FOLDER}/*

fclean: clean 
	rm -f ./*.out

re: fclean all

.PHONY: all clean fclean re bonus
