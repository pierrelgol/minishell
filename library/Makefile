# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 09:37:44 by pollivie          #+#    #+#              #
#    Updated: 2024/05/30 09:37:45 by pollivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = clang
CFLAGS = -Wall                   \
         -Werror                 \
         -Wextra                 \
         -DDEBUG=1               \
         -g3                     \
         -fsanitize=address      \
         -fsanitize=undefined    \
         -fsanitize=integer      \
         -fno-omit-frame-pointer \
         -MMD -MP


RELEASE_CFLAGS = -Wall           \
                 -Werror         \
                 -Wextra         \
		         -O2             \
                 -MMD -MP

INCLUDE = -I$(HDIR)

NAME = libslib.a
HDIR = ./header
SDIR = ./source
ODIR = ./build

SRCS = $(shell find $(SDIR) -name "*.c")

OBJS = $(patsubst $(SDIR)/%.c,$(ODIR)/%.o,$(SRCS))

DEPS = $(OBJS:.o=.d)

GREEN = \033[0;32m
BLUE = \033[0;34m
NC = \033[0m

.PHONY: all clean fclean re help release

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)Creating static library $(NAME)...$(NC)"
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)Static library $(NAME) created successfully!$(NC)"

$(ODIR)/%.o: $(SDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(GREEN)Compiled $< to $@$(NC)"

release: CFLAGS += $(RELEASE_CFLAGS)
release: fclean all

clean:
	@echo "$(BLUE)Cleaning up object files...$(NC)"
	@rm -f $(OBJS) $(DEPS)
	@rm -rf $(ODIR)
	@echo "$(GREEN)Cleaned up object files!$(NC)"

fclean: clean
	@echo "$(BLUE)Cleaning up static library...$(NC)"
	@rm -f $(NAME)
	@echo "$(GREEN)Cleaned up static library!$(NC)"

re: fclean all

help:
	@echo "Usage:"
	@echo "  make [TARGET]"
	@echo ""
	@echo "Targets:"
	@echo "  all        - Build the static library (default)"
	@echo "  release    - Build an optimized release version of the static library"
	@echo "  clean      - Remove object files and dependencies"
	@echo "  fclean     - Remove object files, dependencies, and the static library"
	@echo "  re         - Rebuild everything from scratch"
	@echo "  help       - Show this help message"

-include $(DEPS)

