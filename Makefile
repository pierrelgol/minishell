# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 16:59:55 by pollivie          #+#    #+#              #
#    Updated: 2024/04/19 17:07:46 by pollivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and Flags
CC = clang
CFLAGS = -Wall                   \
         -Werror                 \
         -Wextra                 \
         -DDEBUG=1               \
         -DDIRECT_IO=1           \
         -fsanitize=address      \
         -fsanitize=undefined    \
         -fsanitize=integer      \
         -g3                     \
         -fno-omit-frame-pointer \
         -MMD -MP

RELEASE_CFLAGS = -Wall           \
                 -Werror         \
                 -Wextra         \
                 -O2             \
                 -MMD -MP

INCLUDE = -I$(EXE_HEADER_DIR)

# Executable and Libraries
EXE_NAME = minishell
LIBRARY_DIR = ./library
LIB_NAME = $(LIBRARY_DIR)/libslib.a

# Libft Paths
LIBFT_DIR = ./libft
LIBFT_NAME = $(LIBFT_DIR)/libft.a

# Source and Object Directories
EXE_HEADER_DIR = ./header
EXE_SOURCE_DIRS = source/.                   \
                  source/bifernan            \
                  source/core                \
                  source/debug               \
                  source/environment         \
                  source/hashmap             \
                  source/input               \
                  source/lexer               \
                  source/linker              \
                  source/tokenizer           \
                  source/token               \
                  source/prompt              \
                  source/GLUE                \
                  source/utils               
ODIR = ./build

SRCS = $(foreach dir,$(EXE_SOURCE_DIRS),$(wildcard $(dir)/*.c))
OBJS = $(patsubst %.c,$(ODIR)/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)

# Colors
GREEN = \033[0;32m
BLUE = \033[0;34m
NC = \033[0m

# Build Rules
.PHONY: all clean fclean re release

all: $(EXE_NAME)

# Ensure libft.a and libslib.a are built before the executable
$(EXE_NAME): $(OBJS) $(LIB_NAME) $(LIBFT_NAME)
	@echo "$(BLUE)Creating executable $(EXE_NAME)...$(NC)"
	@$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIBRARY_DIR) -L$(LIBFT_DIR) -lslib -lft -lreadline
	@echo "$(GREEN)Executable $(EXE_NAME) created successfully!$(NC)"

$(ODIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(GREEN)Compiled $< to $@$(NC)"

# Building the library in ./library
$(LIB_NAME):
	@echo "$(BLUE)Building library $(LIB_NAME)...$(NC)"
	@make -C $(LIBRARY_DIR)
	@echo "$(GREEN)Library $(LIB_NAME) built successfully!$(NC)"

# Compilation rules for libft
$(LIBFT_NAME):
	@echo "$(BLUE)Building libft library $(LIBFT_NAME)...$(NC)"
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)Library $(LIBFT_NAME) built successfully!$(NC)"

release: CFLAGS += $(RELEASE_CFLAGS)
release: fclean all

clean:
	@echo "$(BLUE)Cleaning up object files...$(NC)"
	@rm -f $(OBJS) $(DEPS)
	@rm -rf $(ODIR)
	@echo "$(GREEN)Cleaned up object files!$(NC)"
	@make -C $(LIBRARY_DIR) clean
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(BLUE)Cleaning up executable and libraries...$(NC)"
	@rm -f $(EXE_NAME)
	@make -C $(LIBRARY_DIR) fclean
	@make -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)Cleaned up executable and libraries!$(NC)"

re: fclean all

-include $(DEPS)
