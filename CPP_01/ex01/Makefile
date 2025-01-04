CC=c++  -Wall -Wextra -Werror -g -std=c++98 -pedantic
SRC=Zombie.cpp zombieHorde.cpp main.cpp
OBJ=$(SRC:.cpp=.o)

all: zombie

zombie: $(OBJ)
	$(CC) -o zombieHorde $(OBJ)
	@echo "\033[1;32mBuild completed successfully!\033[0m"

%.o: %.cpp
	$(CC) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "\033[1;31mObject files removed!\033[0m"

fclean: clean
	@rm -f zombieHorde
	@echo "\033[1;31mExecutable removed!\033[0m"

re: fclean all