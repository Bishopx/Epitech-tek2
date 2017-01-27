RM      	= rm -f

NAME_SNAKE  = 	./games/lib_arcade_snake.so
NAME_STAR  	= 	./games/lib_arcade_solarfox.so
NAME_LIB1 	= 	./lib/lib_arcade_sdl.so
NAME_LIB2 	= 	./lib/lib_arcade_opengl.so
NAME_LIB3 	= 	./lib/lib_arcade_ncurses.so
NAME_EXEC	= 	arcade

CXXFLAGS 	=	-Wall -Wextra -std=gnu++11 -Werror -g
CXXFLAGS 	+=	-I./Games/Snake/include -I./Gui/include -I./include -I./Games
CXXFLAGS 	+= 	-I./Games/SolarFox/include -fPIC 

LDXXFLAGS 	= 	-lSDL -lSDL_ttf -lcurses -lGL -lGLU -lglut
LDXXFLAGS 	+= 	-std=gnu++11
LDXXFLAGS 	+= 	-shared

LDEXECFLAGS =	-ldl

SRCS_EXEC 	= 	src/main.cpp \
				src/CoreProgram.cpp \
				src/play.cpp

SRCS_SNAKE 	= 	Games/Snake/Snake.cpp \
				Games/Snake/Food.cpp \
				Games/Snake/CoreSnake.cpp \
				Games/Snake/Play.cpp \

SRCS_LIB1 	=  	Gui/SdlGui.cpp

SRCS_LIB2 	=  	Gui/GlGui.cpp

SRCS_LIB3 	=  	Gui/NCurseGui.cpp

SRCS_STAR 	=	Games/SolarFox/Player.cpp \
				Games/SolarFox/Powerup.cpp \
				Games/SolarFox/CoreFox.cpp \
				Games/SolarFox/Play.cpp \
				Games/SolarFox/Enemy.cpp
				
OBJS_EXEC 	= 	$(SRCS_EXEC:.cpp=.o)
OBJS_SNAKE  = 	$(SRCS_SNAKE:.cpp=.o)
OBJS_STAR 	= 	$(SRCS_STAR:.cpp=.o)
OBJS_LIB1 	= 	$(SRCS_LIB1:.cpp=.o)
OBJS_LIB2 	= 	$(SRCS_LIB2:.cpp=.o)
OBJS_LIB3 	= 	$(SRCS_LIB3:.cpp=.o)

all: $(NAME_SNAKE) $(NAME_STAR) $(NAME_EXEC) $(NAME_LIB1) $(NAME_LIB2) $(NAME_LIB3)

$(NAME_EXEC): $(OBJS_EXEC)
	g++ $(OBJS_EXEC) $(LDEXECFLAGS) -o $(NAME_EXEC)

$(NAME_SNAKE): $(OBJS_SNAKE)
	g++ $(OBJS_SNAKE) -shared -o $(NAME_SNAKE) 

$(NAME_STAR) : $(OBJS_STAR)
	g++ $(OBJS_STAR) -shared -o $(NAME_STAR)

$(NAME_LIB1) : $(OBJS_LIB1)
	g++ $(OBJS_LIB1) $(LDXXFLAGS) -o $(NAME_LIB1)

$(NAME_LIB2) : $(OBJS_LIB2)
	g++ $(OBJS_LIB2) $(LDXXFLAGS) -o $(NAME_LIB2)

$(NAME_LIB3) : $(OBJS_LIB3)
	g++ $(OBJS_LIB3) $(LDXXFLAGS) -o $(NAME_LIB3)
		
clean:
	$(RM) $(OBJS_SNAKE)
	$(RM) $(OBJS_STAR)
	$(RM) $(OBJS_EXEC)
	$(RM) $(OBJS_LIB1)
	$(RM) $(OBJS_LIB2)
	$(RM) $(OBJS_LIB3)

fclean: clean
	$(RM) $(NAME_SNAKE)
	$(RM) $(NAME_STAR)
	$(RM) $(NAME_EXEC)
	$(RM) $(NAME_LIB1)
	$(RM) $(NAME_LIB2)
	$(RM) $(NAME_LIB3)

re: fclean all

.PHONY: all clean fclean re
