CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = phonebook
SRC = Phonebook.cpp

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@printf "Executable ready\n"

clean:
	@rm -f $(NAME)
	@printf "Executable removed\n"

re: clean all

.PHONY: all clean re