SERVER	 	= minitalk_server.c
CLIENT      = minitalk_client.c

NAME = SERVER CLIENT
CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror



all: 			${NAME}

$(NAME) : $(SERVER) $(CLIENT)
			$(CC) $(CFLAGS) -I includes lib.c $(SERVER) -o server 
			$(CC) $(CFLAGS) -I includes lib.c $(CLIENT) -o client


clean:
				${RM} server 

fclean:			clean
				${RM} client


re:				fclean all

.PHONY:			all clean fclean re