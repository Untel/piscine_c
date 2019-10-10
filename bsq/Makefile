
SRCS_DIR		= ./srcs

_SRCS			= main.c file.c map.c utils.c run.c

SRCS			= $(addprefix ${SRCS_DIR}/,${_SRCS})

OBJS			= ${SRCS:.c=.o}

INCLUDES_DIR	= ./includes

CFLAGS			= -Wall -Wextra -Werror -I ${INCLUDES_DIR}

CC				= gcc

RM				= rm -f

NAME			= bsq

MAP_NAME		= test.map

MAP_OPTS		= 20 20 1

${NAME}:		${OBJS}
				${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:			${NAME}

clean:			
				${RM} ${OBJS}

fclean:			clean mclean
				${RM} ${NAME}

re:				fclean all

mclean:
				${RM} *.map

mmap:			mclean all
				perl board.pl ${MAP_OPTS} >> 1.map
				perl board.pl 10 20 1 >> 2.map
				perl board.pl 100 40 2 >> 3.map
				./${NAME} 1.map 2.map 3.map

map:			mclean
				perl board.pl ${MAP_OPTS} >> ${MAP_NAME}

test:			all
				./${NAME} ${MAP_NAME}

norme:			
				norminette ${SRCS} ${INCLUDES_DIR}/*.h

.PHONY:			all clean fclean re
