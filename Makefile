NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = -I./includes -I./libft/

SRCS_DIR = srcs/
SRCS = ft_printf.c \
	ft_print_c.c \
	ft_print_s.c \
	ft_print_d.c \
	ft_print_u.c \
	ft_print_p.c \
	ft_print_hexlower.c \
	ft_print_hexupper.c \

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
FULL_OBJS = $(addprefix $(OBJS_DIR), $(OBJS))

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

TEST_MAIN_SRC = test.c
TEST_PROG_NAME = a.out

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS_DIR) $(FULL_OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(FULL_OBJS)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJS_DIR) :
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJS_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -f includes/ft_printf.h.gch
	rm -f $(TEST_PROG_NAME)

re: fclean all

run: $(NAME) test.c
	$(CC) $(CFLAGS) $(HEADER) $(TEST_MAIN_SRC) $(NAME) $(LIBFT) -o $(TEST_PROG_NAME)
	./$(TEST_PROG_NAME)

.PHONY: all clean fclean re run