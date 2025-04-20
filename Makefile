NAME = minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror -I/home/elkharti/projects/minishell/includes
LDFLAGS = -lreadline

SRCS = srcs/main.c srcs/parsing/parser.c srcs/execution/builtin.c \
	srcs/execution/utils/utils00.c srcs/execution/executor.c srcs/parsing/split.c  srcs/parsing/trim.c 


OBJ = $(SRCS:.c=.o)


LIBFT_DIR = srcs/parsing/libft
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
