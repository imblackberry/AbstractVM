NAME = avm

SRC =   main.cpp OperandFactory.cpp Operand.cpp 

SRCDIR = sources/

OBJDIR = objects/

OBJ = $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

FLAGS = -Wall -Werror -Wextra 

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ) ./headers/*.hpp
	g++ -std=c++14 $(FLAGS) $(OBJ) -o $(NAME)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJ) : $(OBJDIR)%.o : $(SRCDIR)%.cpp ./headers/*.hpp
	g++ -std=c++14 $(FLAGS) -o $@ -c $< -I ./headers

debug:
	g++ -std=c++14 -g sources/*.cpp -I ./headers -o debug

clean:
	rm -rf $(OBJDIR) debug

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)