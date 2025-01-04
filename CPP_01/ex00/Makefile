CC=c++  -Wall -Wextra -Werror -g -std=c++98 -pedantic
SRC=Zombie.cpp newZombie.cpp randomChump.cpp main.cpp
OBJ=$(SRC:.cpp=.o)

all: zombie

zombie: $(OBJ)
	$(CC) -o zombie $(OBJ)
	@echo "\033[1;32mBuild completed successfully!\033[0m"

%.o: %.cpp
	$(CC) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "\033[1;31mObject files removed!\033[0m"

fclean: clean
	@rm -f zombie
	@echo "\033[1;31mExecutable removed!\033[0m"

re: fclean all