
SRCS_DIR		= srcs

_SRCS			= ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

SRCS			= $(addprefix ${SRCS_DIR}/,${_SRCS})

_OBJS			= ${_SRCS:.c=.o}

OBJS			= ${SRCS:.c=.o}

INCLUDES_DIR	= includes

_INCLUDES		= ft.h

INCLUDES		= $(addprefix ${INCLUDES_DIR}/, ${_INCLUDES})

FLAGS			= -Wall -Wextra -Werror

GCC				= gcc

AR				= ar rc

RM				= rm -f

NAME			= libft.a

.c.o:
				${GCC} ${FLAGS} -I ${INCLUDES_DIR}/ -c $< -o $@

${NAME}:		${OBJS}
				${AR} ${NAME} ${OBJS}

all:			${NAME}

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
