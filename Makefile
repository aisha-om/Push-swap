NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
SRCS	= stack.c libft.c\
          simple_algo.c\
          compute_disorder.c\
		  complex_algo.c\
		  medium_algo.c\
		  adaptive.c\
		  main.c

OBJS	= ${SRCS:%.c=%.o}
RM		= rm -f
all: ${NAME}

PRINTF_DIR	= ft_printf
PRINTF_LIB	= ${PRINTF_DIR}/libftprintf.a
${PRINTF_LIB}:
	${MAKE} -C ${PRINTF_DIR}

${NAME}: ${PRINTF_LIB} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${PRINTF_LIB} -o ${NAME}


%.o: %.c push_swap.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}
	${MAKE} -C ${PRINTF_DIR} clean

fclean: clean
	${RM} ${NAME}
	${MAKE} -C ${PRINTF_DIR} fclean

re: fclean all
.PHONY: all clean fclean re