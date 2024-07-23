CC = cc
CFLAGS = 

NAME = libftprintf.a
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = $(wildcard ./src/ft_*.c)
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	@mkdir -p temp_libft_objs
	@cd temp_libft_objs && ar x ../$(LIBFT)
	ar rcs $(NAME) $(OBJS) temp_libft_objs/*.o
	@rm -rf temp_libft_objs

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus:

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) a.out
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re