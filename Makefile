NAME		= get_next_line.out

SRC_FILES	= get_next_line.c get_next_line_utils.c main.c
OBJ_FILES	= $(SRC_FILES:%.c=${BIN_FOLDER}/%.o)
INC_FOLDER	= .
BIN_FOLDER  = ./bin

CC			= cc
CFLAGS		= -Wall -Werror -Wextra
DFLAGS		= -D BUFFER_SIZE=30

all: ${NAME}

${NAME}: ${OBJ_FILES}
	${CC} ${CFLAGS} -o ${NAME} $^

${BIN_FOLDER}/%.o:%.c
	mkdir -p ${BIN_FOLDER}
	${CC} ${CFLAGS} ${DFLAGS} -I ${INC_FOLDER} -o $@ -c $^

clean:
	rm -f ${BIN_FOLDER}/*

fclean: clean 
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
