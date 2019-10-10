
SRCS_DIR		= .

_SRCS			= main.c ops.c ft_atoi.c ft_putnbr.c

SRCS			= $(addprefix ${SRCS_DIR}/,${_SRCS})

OBJS			= ${SRCS:.c=.o} 

_INCLUDES		= ops.h

INCLUDES		= ${_INCLUDES}

INCLUDES_DIR	= .

CFLAGS			= -Wall -Wextra -Werror

CC				= gcc

RM				= rm -f

NAME			= do-op

${NAME}:		${OBJS}
				${CC} ${CFLAGS} -I ${INCLUDES_DIR} ${OBJS} -o ${NAME}

all:			${NAME}

clean:			
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
