##
## Makefile for myftp in /home/ploujo_c/tek2/unix/PSU_2015_myftp
## 
## Made by Christophe Ploujoux
## Login	 <ploujo_c@epitech.net>
## 
## Started on	Fri May	13 14:19:32 2016 Christophe Ploujoux
## Last update	Fri May	13 14:19:32 2016 Christophe Ploujoux
##

RM 				= rm -f

NAME_SERVER 	= server
NAME_CLIENT 	= client

CFLAGS 			=	-Wall -Wextra -Werror -g
CFLAGS 			+=	-I./include


SRCS_SERVER		=	srcs/server/main.c \
					srcs/server/handle_clients.c \
					srcs/server/handle_server.c \
					srcs/server/cmd_login.c \
					srcs/server/cmd_channel.c \
					srcs/server/cmd_message.c \
					srcs/server/cmd_join.c \
					srcs/server/cmd_names.c \
					srcs/server/cmd_part.c \
					srcs/server/cmd_quit.c \
					srcs/server/cmd_nick.c \
					srcs/server/msg_nick.c \
					srcs/server/msg_channel.c \
					srcs/server/check_arg.c \
					srcs/channel.c \
					srcs/get_next_line.c \
					srcs/xfunction.c \
					srcs/basic_functions.c

SRCS_CLIENT		=	srcs/client/main.c \
					srcs/client/handle_server.c \
					srcs/client/cmd.c \
					srcs/client/cmd_send.c \
					srcs/client/cmd_server.c \
					srcs/client/cmd_names.c \
					srcs/client/fonction_ptr.c \
					srcs/channel.c \
					srcs/get_next_line.c \
					srcs/xfunction.c \
					srcs/basic_functions.c					

OBJS_SERVER     = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT     = $(SRCS_CLIENT:.c=.o)

all: server client

server: $(OBJS_SERVER)
	gcc $(OBJS_SERVER) -o $(NAME_SERVER)

client: $(OBJS_CLIENT)
	gcc $(OBJS_CLIENT) -o $(NAME_CLIENT)

clean:
	$(RM) $(OBJS_SERVER)
	$(RM) $(OBJS_CLIENT)

fclean: clean
	$(RM) $(NAME_SERVER)
	$(RM) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re
