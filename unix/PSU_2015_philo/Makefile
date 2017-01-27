##
## Makefile for philo in /home/ploujo_c/tek2/unix/PSU_2015_philo
## 
## Made by Christophe Ploujoux
## Login	 <ploujo_c@epitech.net>
## 
## Started on	Thu Mar	3 13:24:02 2016 Christophe Ploujoux
## Last update	Thu Mar	3 13:24:02 2016 Christophe Ploujoux
##

RM      = rm -f

NAME    = philo

CFLAGS +=	-Wall -Wextra -Werror
CFLAGS += 	-I./include

LDFLAGS = -lriceferee -pthread

SRC     = 	main.c \
			eat.c \
			rest.c \
			think.c \
			utils.c

OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) -L./lib $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
