NAME = worker

SRC =  main.cpp Worker.cpp Shovel.cpp Hammer.cpp Tool.cpp Workshop.cpp Position.cpp Statistic.cpp

OBJ =  main.o Worker.o Shovel.o Hammer.o Tool.o Workshop.o Position.o Statistic.o

HED = Position.hpp Statistic.hpp Worker.hpp Shovel.hpp Tool.hpp Hammer.hpp Position.hpp Statistic.hpp

CC = clang++ -std=c++98

# FLAGS = -Wall -Werror -Wextra
# FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@

%.o:%.cpp $(HED)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all