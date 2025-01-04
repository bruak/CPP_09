NAME = philo
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror  #-pthread -fsanitize=address 
RM = rm -rf
LIBRARY = philo.h

SRCS = allocation.c first_arg_check.c free_destroy_2.c free_destroy.c init.c main.c one_philo.c start.c start_2.c time_sleep.c
OBJS = $(SRCS:.c=.o)

GREEN = \033[0;32m
CYAN = \033[0;36m
RED = \033[0;31m
YELLOW = \033[1;33m
MAGENTA = \033[1;35m
RESET = \033[0m


all : $(NAME)

%.o : %.c $(LIBRARY)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiled $< successfully$(RESET)"

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "$(CYAN)Executable $@ created successfully$(RESET)"
	@echo "$(MAGENTA)*******************************************************************************$(RESET)"
	@echo "$(MAGENTA)*                           ^?JJJJJJJJJJ7.    :?JJJJJJJJJJ~?JJJJJJJJJJJ:      *"
	@echo "$(MAGENTA)*                         ^5&@@@@@@@@@#J:     ~@@@@@@@@@G!.&@@@@@@@@@@@!      *"
	@echo "$(MAGENTA)*                       ~P@@@@@@@@@@B7.       ~@@@@@@@5^  .#@@@@@@@@@@@!      *"
	@echo "$(MAGENTA)*                     !G@@@@@@@@@@G!          ~@@@@&Y^    .#@@@@@@@@@@@!      *"
	@echo "$(MAGENTA)*                  .7B@@@@@@@@@@P~            ~@@&J:      .#@@@@@@@@@@@!      *"
	@echo "$(MAGENTA)*                .?B@@@@@@@@@@P~              ~#J.         #@@@@@@@@@@@!      *"
	@echo "$(MAGENTA)*              :J#@@@@@@@@@&5^                ..         .J@@@@@@@@@@@P:      *"
	@echo "$(MAGENTA)*            :Y&@@@@@@@@@&Y:                           :J#@@@@@@@@@&5^        *"
	@echo "$(MAGENTA)*          ^5&@@@@@@@@@#J:                           ^Y&@@@@@@@@@&J:          *"
	@echo "$(MAGENTA)*        ~P@@@@@@@@@@B?.                           ^5@@@@@@@@@@#?.            *"
	@echo "$(MAGENTA)*      ~P@@@@@@@@@@B7                            ~P@@@@@@@@@@B?.              *"
	@echo "$(MAGENTA)*    !G@@@@@@@@@@B7. ....................      !G@@@@@@@@@@B7                 *"
	@echo "$(MAGENTA)*   !@@@@@@@@@@@@###&&&&&&&&&&&&&&&&&&&&&7    ^@@@@@@@@@@@&:         :Y~      *"
	@echo "$(MAGENTA)*   !@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@?    ~@@@@@@@@@@@&:       ^5&@!      *"
	@echo "$(MAGENTA)*   !@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@?    ~@@@@@@@@@@@&:     ~P@@@@!      *"
	@echo "$(MAGENTA)*   !@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@?    ~@@@@@@@@@@@&:   !G@@@@@@!      *"
	@echo "$(MAGENTA)*   ^PPPPPPPPPPPPPPPPPPPPPPPP#@@@@@@@@@@@?    ~@@@@@@@@@@@&..7B@@@@@@@@!      *"
	@echo "$(MAGENTA)*                            P@@@@@@@@@@@?    ^GGGGGGGGGGGP~YGGGGGGGGGG~      *"
	@echo "$(MAGENTA)*                            P@@@@@@@@@@@?                                    *"
	@echo "$(MAGENTA)*                            P@@@@@@@@@@@?                                    *"
	@echo "$(MAGENTA)*                            P@@@@@@@@@@@?                                    *"
	@echo "$(MAGENTA)*                            G@@@@@@@@@@@?                                    *"
	@echo "$(MAGENTA)*                            !JJJJJJJJJJJ^                                    *"
	@echo "$(MAGENTA)*******************************************************************************$(RESET)"

clean :
	$(RM) $(OBJS)
	@echo "$(RED)Cleaned up object files$(RESET)"

fclean : clean
	$(RM) $(NAME)
	@echo "$(RED)Cleaned up executable$(RESET)"

re : fclean all

.PHONY : all clean fclean re
