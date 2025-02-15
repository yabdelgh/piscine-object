NAME = bank

SRC =  main.cpp

OBJ =  main.o

HED =

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