CC  = gcc
SRC = Main.c Example.c
BIN = Main

all:
	@$(CC) $(SRC) -o $(BIN) -Wall -Werror -g

run:
	@./$(BIN)

valgrind:
	@valgrind --tool=memcheck --leak-check=full --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BIN)
