##
## Makefile for menger in /home/ploujo_c/tek2/Piscine/piscine_cpp_d01/ex01
## 
## Made by Christophe Ploujoux
## Login   <ploujo_c@epitech.net>
## 
## Started on  Wed Jan  6 14:07:13 2016 Christophe Ploujoux
## Last update Wed Jan  6 20:42:26 2016 Christophe Ploujoux
##

RM      = rm -f

NAME    = menger

CFLAGS	= -Wextra -Wall -Werror -std=gnu99

SRC     = 	main.c \
		menger.c

OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc -lm $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
