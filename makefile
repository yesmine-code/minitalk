SERVER	 	= minitalk_server.c
CLIENT      = minitalk_client.c

NAME = SERVER CLIENT
CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror



all: 			${NAME}

$(NAME) : $(SERVER) $(CLIENT)
			$(CC) $(CFLAGS) lib.c $(SERVER) -o server 
			$(CC) $(CFLAGS) lib.c $(CLIENT) -o client


clean:
				${RM} ${OBJS} 

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re