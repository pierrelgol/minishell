NAME = minishell
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
SRCS := $(wildcard source/*.c)
OBJS = $(SRCS:.c=.o)
INCLUDES = minishell.h
LIBFT = libft/libft.a

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lft

$(LIBFT) :
	@$(MAKE) -C libft/

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX_LIB):
	@make -C $(MLX_DIR)

clean:
	@$(MAKE) -C libft/ clean
	@rm -f $(OBJS)
	
fclean: clean
	@$(MAKE) -C libft/ fclean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
