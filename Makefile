NAME =	test_sfml

SRC =	main.cpp\
		SoundManager.cpp\
		SoundEffect.cpp\

OBJ =	$(SRC:.cpp=.o)

INC = -I$(HOME)/.brew/include/

LIB = -L$(HOME)/.brew/lib -lpng -lGLEW -ljpeg -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window 
C++ =	g++ -g -Wall -Wextra -Werror -O3 -std=c++11

%.o:		%.cpp
	@echo "\033[1;36;m[Compiling $<]\t\033[0m: " | tr -d '\n'
	$(C++) -c $< $(INC)

all:		$(NAME)

$(NAME):	$(OBJ) 
	@echo "\033[1;35;m[Linking] \t\t\033[0m: " | tr -d '\n'
	$(C++) -o $@ $(LIB) $(OBJ) 
	@echo "\033[1;32;m[Success] \t\t\t\033[0m"

clean:
	@echo "\033[0;33;m[Cleaning] \t\t\033[0m: " | tr -d '\n'
	rm -f $(OBJ)

fclean:		clean
	@echo "\033[0;31;m[Deleting $(NAME)] \t\033[0m: " | tr -d '\n'
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re