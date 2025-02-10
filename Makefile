CC = gcc
C_FLAGS = -Wall -Werror -Wextra
SRC = $(wildcard srcs/*.c)
OBJ = ${SRC:.c=.o}
H_DIR = includes
HDR = ${H_DIR}/map.h
NAME = bsq
all: bsq

bsq: ${OBJ}
	${CC} ${OBJ} -o ${NAME}

%.o:%.c ${HDR}
	${CC} ${C_FLAGS} -I./${H_DIR} -c $< -o $@

clean: 
	rm ${OBJ}

fclean: clean
	rm ${NAME}
