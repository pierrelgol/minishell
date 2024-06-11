# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bifernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 16:13:33 by bifernan          #+#    #+#              #
#    Updated: 2023/11/24 11:32:43 by bifernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and Flags
CC = clang
CFLAGS = -Wall                   \
         -Werror                 \
         -Wextra                 \
         -DDEBUG=1               \
         -g3                     \
         -fno-omit-frame-pointer \
         -MMD -MP

RELEASE_CFLAGS = -Wall           \
                 -Werror         \
                 -Wextra         \
                 -O2             \
                 -MMD -MP

# Directories
SRC_DIR = ./srcs
INC_DIR = ./includes
BUILD_DIR = ./build

# Files
NAME = libft.a
SRCS = $(shell find $(SRC_DIR) -name "*.c")
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)

# Include directories
INCLUDE = -I$(INC_DIR)

# Colors for output
GREEN = \033[0;32m
BLUE = \033[0;34m
NC = \033[0m

# Targets
.PHONY: all clean fclean re release help

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)Creating static library $(NAME)...$(NC)"
	@ar rcs $@ $^
	@echo "$(GREEN)Static library $(NAME) created successfully!$(NC)"

# Compilation rule for object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(GREEN)Compiled $< to $@$(NC)"

release: CFLAGS += $(RELEASE_CFLAGS)
release: fclean all

clean:
	@echo "$(BLUE)Cleaning up object files...$(NC)"
	@rm -f $(OBJS) $(DEPS)
	@rm -rf $(BUILD_DIR)
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
