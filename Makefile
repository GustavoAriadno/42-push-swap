NAME	=	push_swap

CC		=	clang
C_FLAGS	=	-c		\
			-Wall	\
			-Wextra	\
			-Werror	\
			-I${INCLUDE}	\
			-I./${LIB_DIR}

INCLUDE	=	./include

LIB_DIR	=	libft
LIBFT	=	${LIB_DIR}/libft.a

SRC_DIR	=	src
SRC		=	push_swap.c	\
			input.c		\
			llist.c		\
			free.c		\
			check.c

vpath %.c ${SRC_DIR}

OBJ_DIR	=	obj
OBJ		=	$(patsubst %.c, ${OBJ_DIR}/%.o, ${SRC})


all		:	${NAME}

${NAME}	:	${OBJ} ${LIBFT}
			${CC} -o $@ $^

${LIBFT}:
			${MAKE} -C ${LIB_DIR}

${OBJ_DIR}/%.o	:	%.c
			mkdir -p ${OBJ_DIR}
			${CC} ${C_FLAGS} $< -o $@

# test	:

clean	:
			rm -rf ${OBJ}

fclean	:	clean
			rm -rf ${NAME}

re		:	fclean all

.PHONY	:	all test clean fclean re