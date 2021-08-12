SRCS_S          = server.c
SRCS_C			= client.c

OBJS_S          = $(SRCS_S:.c=.o)
OBJS_C          = $(SRCS_C:.c=.o)

CC              = gcc
RM              = rm -f
CFLAGS          =  -Wall -Werror -Wextra
NAME_S          = server
NAME_C          = client

all:	$(NAME_S) $(NAME_C)

$(NAME_S):	$(OBJS_S)
					gcc ${CFLAGS} -o ${NAME_S}  ${OBJS_S} 

$(NAME_C):	$(OBJS_C)
					gcc ${CFLAGS} -o ${NAME_C}  ${OBJS_C} 

clean:
			$(RM) $(OBJS_S)
			$(RM) $(OBJS_C)

fclean:	clean
			$(RM) $(NAME_S)
			$(RM) $(NAME_C)

re:		fclean $(NAME_S) $(NAME_C)

.PHONY:	all clean fclean re