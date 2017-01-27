##
## Makefile for myftp in /home/ploujo_c/tek2/unix/PSU_2015_myftp
## 
## Made by Christophe Ploujoux
## Login	 <ploujo_c@epitech.net>
## 
## Started on	Fri May	13 14:19:32 2016 Christophe Ploujoux
## Last update	Fri May	13 14:19:32 2016 Christophe Ploujoux
##

RM      = rm -f

NAME    = server

CFLAGS =	-Wall -Wextra -Werror
CFLAGS +=	-I./include


SRCS	=	srcs/main.c \
		srcs/handle_clients.c \
		srcs/cmd_login.c \
		srcs/cmd_pasv.c \
		srcs/cmd_port.c \
		srcs/cmd_connected.c \
		srcs/cmd_data.c \
		srcs/check_arg.c \
		srcs/get_next_line.c \
		srcs/xfunction.c \
		srcs/basic_functions.c

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
