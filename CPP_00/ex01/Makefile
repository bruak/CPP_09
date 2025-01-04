CC=c++ -std=c++98 -g
SRC=MyPhoneBook.cpp Contact.cpp main.cpp
OBJ=$(SRC:.cpp=.o)

all: MyPhoneBook

MyPhoneBook: $(OBJ)
	$(CC) -o phonebook $(OBJ)
	@echo "\033[1;32mBuild completed successfully!\033[0m"

%.o: %.cpp
	$(CC) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "\033[1;31mObject files removed!\033[0m"

fclean: clean
	@rm -f phonebook
	@echo "\033[1;31mExecutable removed!\033[0m"

re: fclean all