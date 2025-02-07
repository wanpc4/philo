CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

SRC_DIR = srcs
OBJ_DIR = obj
INC = -Iinclude
LIB = -lpthread

EXE_NAME = philo

SRC = $(wildcard $(SRC_DIR)/*.c) main.c
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(EXE_NAME)

$(EXE_NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(LIB) $(OBJ) -o $(EXE_NAME)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

fsanMem: $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(LIB) -fsanitize=address $(OBJ) -o $(EXE_NAME)

fsanThread: $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(LIB) -fsanitize=thread $(OBJ) -o $(EXE_NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(EXE_NAME)

re: fclean all

.PHONY: all clean fclean re
