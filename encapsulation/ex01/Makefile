NAME = graph

SRC =  main.cpp graph.cpp

OBJ =  main.o graph.o

HED = graph.hpp

CC = clang++ -std=c++98

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@

%.opp:%.cpp $(HED)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all