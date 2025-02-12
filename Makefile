CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

SRC_DIR = srcs
OBJ_DIR = obj

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
INC = -I.
LIB = -lpthread

EXE_NAME = philo

all: $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(LIB) $(OBJ) main.c -o $(EXE_NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

fsanMem:
	$(CC) $(CFLAGS) $(INC) $(LIB) -fsanitize=address main.c -o $(EXE_NAME) $(OBJ)

fsanThread:
	$(CC) $(CFLAGS) $(INC) $(LIB) -fsanitize=thread main.c -o $(EXE_NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXE_NAME)

re: fclean all

.PHONY: all clean fclean re
