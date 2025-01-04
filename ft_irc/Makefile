NAME = ircserv
CC = c++
CXXFLAGS = -Wall -Wextra -Werror  -Iinclude -g -std=c++98
SRC =	src/main.cpp			\
		src/Command/Bot.cpp		\
		src/Command/Cap.cpp		\
		src/Command/Command.cpp	\
		src/Command/Join.cpp	\
		src/Command/Kick.cpp	\
		src/Command/Mode.cpp	\
		src/Command/Nick.cpp	\
		src/Command/Notice.cpp	\
		src/Command/Part.cpp	\
		src/Command/Pass.cpp	\
		src/Command/PrivMsg.cpp	\
		src/Command/Quit.cpp	\
		src/Command/User.cpp	\
		src/Command/Who.cpp		\
		src/Network/Channel.cpp	\
		src/Network/Client.cpp	\
		src/Network/Server.cpp	\
		src/Parser.cpp			\

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
OBJ_DIR = .objs


all: $(NAME)

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CXXFLAGS) $(SRC) -o $(NAME)
	@echo "\033[1;32mBuild completed successfully!\033[0m"

clean:
	@rm -f $(OBJ)
	@echo "\033[1;31mObject files removed!\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;31mExecutable removed!\033[0m"

re: fclean all
r : re
f : fclean
