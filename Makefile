CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

SERVER = server

CLIENT = client

SRC_SERV = server.c

SRC_CLIE = client.c

LIBFT = libft/libft.a

HEADER = mini_talk.h

OBJ_SERV = $(SRC_SERV:.c=.o)

OBJ_CLIE = $(SRC_CLIE:.c=.o)

GREEN = \033[0;32m
BLUE = \033[0;34m
CYAN = \033[0;36m
YELLOW = \033[0;33m
PURPLE = \033[0;35m
NC = \033[0m

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SERV) $(HEADER) $(LIBFT)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJ_SERV) $(LIBFT)
	@echo "$(GREEN)		*----------------------------------*\n \
			|        [OK] $(SERVER) created       |\n \
			*----------------------------------*$(NC)"

$(CLIENT): $(OBJ_CLIE) $(HEADER) $(LIBFT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJ_CLIE) $(LIBFT)
	@echo "$(BLUE)		*----------------------------------*\n \
			|        [OK] $(CLIENT) created       |\n \
			*----------------------------------*$(NC)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C libft
	@echo "$(CYAN)		*----------------------------------*\n \
			|    [OK] $(LIBFT) created    |\n \
			*----------------------------------*$(NC)"

clean:
	rm -f $(OBJ_SERV) $(OBJ_CLIE)
	@make -C libft clean
	@echo "$(PURPLE)[OK]$(NC) mini_talk clean completed"

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	@make -C libft fclean
	@echo "$(PURPLE)[OK]$(NC) mini_talk fclean completed"

re: fclean all

.PHONY: all clean fclean re