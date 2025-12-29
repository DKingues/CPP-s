# Name and Compiler

NAME = megaphone

COMPILER = c++

FLAGS = -Wall -Wextra -Werror

EXTRAFLAG = -std=c++98

SRC = megaphone.cpp

# Sources and Objects

OBJ = $(SRC:.cpp=.o)

# Explicit compile rule (silences the g++ command)

%.o: %.cpp
	@$(COMPILER) $(FLAGS) -c -o $@ $<

# Messages

COMP = echo "Program status: \033[1;32m[OK]\033[0m"

DEL = echo "Program status: \033[1;31m[KO]\033[0m"


# Execution

all: $(NAME)
$(NAME): $(OBJ)
	@$(COMPILER) $(FLAGS) $(OBJ) -o $(NAME)
	@$(COMP)
clean:
	@rm -rf $(OBJ)
	@$(DEL)
fclean: clean
	@rm -rf $(NAME)

re: fclean all
