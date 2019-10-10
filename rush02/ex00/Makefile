
SRCS_DIR		= .

_SRCS			= errors.c ft_split.c dict_parser.c main.c ft_putstr.c strs_digits_power.c ft_strjoin.c ft_natoi.c num_to_3digits_tab.c 

SRCS			= $(addprefix ${SRCS_DIR}/,${_SRCS})

_INCLUDES		= ops.h

INCLUDES		= ${_INCLUDES}

INCLUDES_DIR	= .

CFLAGS			= -Wall -Wextra -Werror

CC				= gcc

RM				= rm -f

NAME			= rush02

${NAME}:			
				${CC} ${CFLAGS} -I ${INCLUDES_DIR} ${SRCS} -o ${NAME}

all:			${NAME}

fclean:
				${RM} ${NAME}

clean:			fclean

re:				fclean all

.PHONY:			all fclean clean re
