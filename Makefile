NAME = avm

SRC =   main.cpp Operand.cpp  OperandFactory.cpp

SRCDIR = sources/

OBJDIR = objects/

OBJ = $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

FLAGS = -Wall -Werror -Wextra 

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ) ./headers/*.hpp
	g++ -std=c++11 $(FLAGS) $(OBJ) -o $(NAME) -lncurses

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJ) : $(OBJDIR)%.o : $(SRCDIR)%.cpp ./headers/*.hpp
	g++ -std=c++11 $(FLAGS) -o $@ -c $< -I ./headers

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)