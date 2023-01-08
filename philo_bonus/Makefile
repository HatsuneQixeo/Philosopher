NAME	:=	philo
SRC_DIR	:=	src/
SRCS	:=	${wildcard ${SRC_DIR}*.c}
OBJ_DIR	:=	obj/
OBJS	:=	${patsubst ${SRC_DIR}%.c, ${OBJ_DIR}%.o, ${SRCS}}
INCLUDE	:=	include/
HEADER	:=	${wildcard ${INCLUDE}*.h}
CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror
RM		:=	rm -rf

${OBJ_DIR}%.o : ${SRC_DIR}%.c ${HEADER}
	${CC} ${CFLAGS} -I${INCLUDE} -c $< -o $@

all : ${OBJ_DIR} ${NAME}

${OBJ_DIR} :
	mkdir $@

${NAME} : ${OBJS}
	${CC} ${CFLAGS} $^ -o $@

san :
	${CC} ${CFLAGS} -fsanitize=address -g3 ${SRCS} -o ${NAME}

sant :
	${CC} ${CFLAGS} -fsanitize=thread -g3 ${SRCS} -o ${NAME}

clean :
	${RM} ${OBJ_DIR}

fclean : clean
	${RM} ${NAME}

re : fclean all

norm :
	norminette ${SRCS} ${HEADER}

norme :
	norminette ${SRCS} ${HEADER} | grep "Error"

