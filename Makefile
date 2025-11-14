NAME = libftprintf.a

SRC = ft_printf.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

HEADERS = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

check: norm

norm:
	@clear
	@echo "\n------------ Norm ------------\n"
	@norminette $(SRC) $(SRC_BONUS) libft.h
	@echo

test: $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME)

.PHONY: all clean fclean re

