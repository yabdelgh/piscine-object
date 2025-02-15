NAME = bank

SRC =  main.cpp DivideAndRule.cpp

OBJ =  main.o DivideAndRule.o

HED = DivideAndRule.hpp

CC = clang++ -std=c++98

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@

%.o: %.cpp $(HED)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all