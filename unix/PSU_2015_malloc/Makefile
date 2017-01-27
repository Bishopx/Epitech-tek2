##
## Makefile for libmy in /home/ploujo_c/rendu/Piscine_C_J11/lib/my
## 
## Made by christophe ploujoux
## Login   <ploujo_c@epitech.net>
## 
## Started on  Mon Oct 20 11:03:58 2014 christophe ploujoux
## Last update Thu Feb  4 14:42:48 2016 Christophe Ploujoux
##

RM	= rm -f

NAME	= libmy_malloc_$(HOSTTYPE).so

CFLAGS 	= -Wextra -Wall -Werror

LDFLAGS = -shared -fPIC

SRCS	= malloc.c \
	realloc.c \
	free.c \
	calloc.c

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	gcc $(SRCS) $(LDFLAGS) -o $(NAME)
	ln -s $(NAME) libmy_malloc.so

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) libmy_malloc.so

re: fclean all
