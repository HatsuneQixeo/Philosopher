NAME	:=	philo_bonus
CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror
SRC_DIR	:=	src/
SRCS	:=	${wildcard ${SRC_DIR}*.c}
OBJ_DIR	:=	obj/
OBJS	:=	${patsubst ${SRC_DIR}%.c, ${OBJ_DIR}%.o, ${SRCS}}
INCLUDE	:=	include/
HEADER	:=	${wildcard ${INCLUDE}*.h}
RM		:=	rm -rf

${OBJ_DIR}%.o : ${SRC_DIR}%.c ${HEADER}
	${CC} ${CFLAGS} -I${INCLUDE} -c $< -o $@

all : ${OBJ_DIR} ${NAME}

${OBJ_DIR} :
	mkdir $@

${NAME} : ${OBJS}
	${CC} ${CFLAGS} $^ -o $@

san :
	${CC} ${CFLAGS} -I${INCLUDE} -fsanitize=address -g3 ${SRCS} -o ${NAME}

sant :
	${CC} ${CFLAGS} -I${INCLUDE} -fsanitize=thread -g3 ${SRCS} -o ${NAME}

clean :
	${RM} ${OBJ_DIR}

fclean : clean
	${RM} ${NAME} *.dSYM racing

re : fclean all

norm :
	norminette ${SRCS} ${HEADER}

norme :
	norminette ${SRCS} ${HEADER} | grep "Error"

race : ${patsubst %${OBJ_DIR}main.o, %, ${OBJS}}
	${CC} ${CFLAGS} -I${INCLUDE} $^ race.c -o racing -fsanitize=thread -g3

maintest : ${NAME}
	./$< 4 410 200 200 5
	ps

oddtest : ${NAME}
	./$< 3 610 200 200 5
	ps

dietest : ${NAME}
	./$< 3 410 200 200 5
	ps
