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

SRC_BONNUS = ft_printf_bonus.c \
				src_bonus/ft_alignment_bonus.c \
				src_bonus/ft_atoi_bonus.c \
				src_bonus/ft_utils_bonus.c \
				src_bonus/ft_max_bonus.c \
				src_bonus/ft_swrite_bonus.c \
				src_bonus/ft_format_arg_bonus.c \
				src_bonus/ft_putnbr_base_bonus.c \
				src_bonus/ft_putnbr_bonus.c \
				src_bonus/ft_type_c_bonus.c \
				src_bonus/ft_type_s_bonus.c \
				src_bonus/ft_type_p_bonus.c \
				src_bonus/ft_type_i_bonus.c \
				src_bonus/ft_type_u_bonus.c \
				src_bonus/ft_type_x_bonus.c \
				src_bonus/ft_type_xx_bonus.c \
				src_bonus/ft_type_mod_bonus.c

CC = cc
# CFLAGS = -Wall -Wextra -Werror -I. -g3
CFLAGS = -I. -g3

OBJ_DIR = .obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))
OBJ_BONUS = $(addprefix $(OBJ_DIR)/, $(SRC_BONNUS:%.c=%.o))

HEADERS = ft_printf.h
HEADERS_BONNUS = ft_printf_bonus.h

all: $(NAME)

$(NAME): clean_out $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)

bonus: clean_out $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

clean_out:
	rm -f $(NAME)

fclean: clean clean_out

re: fclean all

check: norm

norm:
	@clear
	@echo "\n------------ Norm ------------\n"
	@norminette $(SRC) $(SRC_BONNUS) $(HEADERS)
	@echo

test: clean_out $(NAME) main.c
	$(CC) $(CFLAGS) main.c $(NAME) -o $(OBJ_DIR)/test.out
	@echo
	@./$(OBJ_DIR)/test.out

test_bonus: clean_out bonus main_bonus.c
	$(CC) main_bonus.c $(NAME) -o $(OBJ_DIR)/test_bonus.out
	@echo
	@./$(OBJ_DIR)/test_bonus.out

.PHONY: all bonus clean clean_out fclean re check norm test test_bonus
