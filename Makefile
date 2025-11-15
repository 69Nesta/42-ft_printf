NAME = libftprintf.a

SRC = ft_printf.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

HEADERS = ft_printf.h

LIBFT_DIR = ./libft
LIBFT = libft.a
LIBFT_CMD = make --no-print-directory -C $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(LIBFT_CMD)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	$(LIBFT_CMD) $@
	rm -f $(NAME)

re: fclean all

check: norm

norm:
	@clear
	@echo "\n------------ Norm ------------\n"
	@norminette $(SRC) $(HEADERS)
	@echo

test: $(NAME) main.c
	$(CC) $(CFLAGS) main.c $(NAME) -o test.out
	@echo
	@./test.out

.PHONY: all clean fclean re
