NAME = minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror -I/home/elkharti/projects/minishell/includes
LDFLAGS = -lreadline

SRCS = main.c parsing/parser.c  \
		 parsing/trim.c 


OBJ = $(SRCS:.c=.o)


LIBFT_DIR = parsing/libft
LIBFT = $(LIBFT_DIR)/libft.a


$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
