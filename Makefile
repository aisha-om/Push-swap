NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
SRCS	= 
OBJ		= ${SRCS:%.c=%.o}
RM		= rm -f

all: ${NAME}


${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} 

%.o: %.c push_swap.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
.PHONY: all clean fclean re 