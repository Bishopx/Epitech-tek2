RM	= 	rm -f

CC	= 	g++

CFLAGS	+=	-Wall -Wextra -Werror

NAME	=	my_cat

SRC	=	main.cpp\

OBJ	= 	$(SRC:.cpp=.o)

all	: 	$(NAME)

$(NAME)	: 	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all re fclean clean