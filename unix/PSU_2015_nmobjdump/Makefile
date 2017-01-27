##
## Makefile for minitalk in /home/ploujo_c/rendu/unix/PSU_2014_minitalk
## 
## Made by Ploujoux Christophe
## Login   <ploujo_c@epitech.net>
## 
## Started on  Tue Mar 17 03:49:40 2015 Ploujoux Christophe
## Last update Sat May 16 12:51:34 2015 Ploujoux Christophe
##

CC	=	gcc

RM      =	rm -f

NAME1   =	my_nm
NAME2	=	my_objdump

SRC1	=	nm-dir/main.c

SRC2	=	objdump-dir/main.c

CFLAGS	+=	-W -Wall -Werror
CFLAGS	+=	-Wextra -pedantic

OBJ1	=	$(SRC1:.c=.o)
OBJ2	=	$(SRC2:.c=.o)

all	:	$(NAME1) $(NAME2)

$(NAME1):	$(OBJ1)
		$(CC) $(OBJ1) -o $(NAME1)

$(NAME2):	$(OBJ2)
		$(CC) $(OBJ2) -o $(NAME2)

clean	:
		$(RM) $(OBJ1)
		$(RM) $(OBJ2)

fclean	:	clean
		$(RM) $(NAME1)
		$(RM) $(NAME2)

re	:	fclean all

.PHONY : all re fclean clean
