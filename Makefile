NAME := philo

SRCS := ${wildcard *.c}

OBJ_DIR := obj/

OBJS := ${patsubst %.c, ${OBJ_DIR}%.o, ${SRCS}}

HEADER := ${wildcard *.h}

CC := gcc

CFLAGS := -Wall -Wextra -Werror

SAN := -fsanitize=address -g3
# SAN := -fsanitize=undefined -g3
SANT := -fsanitize=thread -g3

RM := rm -rf

${OBJ_DIR}%.o : %.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

all : ${OBJ_DIR} ${NAME}

${OBJ_DIR} :
	mkdir $@

${NAME} : ${OBJS} libft/libft.a
	${CC} ${CFLAGS} $^ -o $@

san : ${OBJ_DIR} ${SRCS} ${HEADER}
	${CC} ${CFLAGS} ${SAN} libft/libft.a ${SRCS} -o ${NAME}

sant : ${OBJ_DIR} ${SRCS} ${HEADER}
	${CC} ${CFLAGS} ${SANT} libft/libft.a ${SRCS} -o ${NAME}

clean :
	${RM} ${OBJ_DIR}

fclean : clean
	${RM} ${NAME}

re : fclean all

norm :
	norminette ${SRCS} ${HEADER}

norme : 
	norminette ${SRCS} ${HEADER} | grep Error

libft : 
	make -C libft


