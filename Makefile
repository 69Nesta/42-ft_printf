NAME = libftprintf.a

SRC = ft_printf.c \
		src/ft_utils.c \
		src/ft_putnbr_base.c \
		src/ft_putnbr.c \
		src/ft_type_c.c \
		src/ft_type_s.c \
		src/ft_type_p.c \
		src/ft_type_i.c \
		src/ft_type_u.c \
		src/ft_type_x.c \
		src/ft_type_xx.c \
		src/ft_type_mod.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -g3

OBJ_DIR = .obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

HEADERS = ft_printf.h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(LIBFT_CMD)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean clean_out

re: fclean all

check: norm

clean_out:
	rm -f $(NAME)

norm:
	@clear
	@echo "\n------------ Norm ------------\n"
	@norminette $(SRC) $(HEADERS)
	@echo

test: clean_out $(NAME) main.c
	$(CC) $(CFLAGS) main.c $(NAME) -o $(OBJ_DIR)/test.out
	@echo
	@./$(OBJ_DIR)/test.out

.PHONY: all clean fclean re check norm test
