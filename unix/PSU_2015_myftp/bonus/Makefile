##
## Makefile for myftp in /home/ploujo_c/tek2/unix/PSU_2015_myftp
## 
## Made by Christophe Ploujoux
## Login	 <ploujo_c@epitech.net>
## 
## Started on	Fri May	13 14:19:32 2016 Christophe Ploujoux
## Last update	Fri May	13 14:19:32 2016 Christophe Ploujoux
##

RM      = 	rm -f

NAME    = 	client

CFLAGS	 =	-Wall -Wextra -Werror -g
CFLAGS 	+=	-I./include


SRCS	= 	src_client/main.c \
		src_client/handle_server.c \
		src_client/connect_data.c \
		src_client/cmd_basic.c \
		src_client/cmd_ls.c \
		src_client/cmd_get.c \
		src_client/cmd_put.c \
		src_client/cmd_login.c \
		src_client/cmd_local.c \
		src_client/check_arg.c \
		src_client/get_next_line.c \
		src_client/xfunction.c \
		src_client/basic_functions.c

OBJS     = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
