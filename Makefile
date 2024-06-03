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

CC = clang
CFLAGS = -Wall                   \
         -Werror                 \
         -Wextra                 \
         -fsanitize=address      \
         -fsanitize=undefined    \
         -fsanitize=integer      \
         -DDEBUG=1               \
         -g3                     \
         -fno-omit-frame-pointer \
         -MMD -MP

RELEASE_CFLAGS = -O3 -DNDEBUG
INCLUDE = -I$(EXE_HEADER_DIR)

EXE_NAME = minishell
LIBRARY_DIR = ./library
LIB_NAME = $(LIBRARY_DIR)/libslib.a

EXE_HEADER_DIR = ./header
EXE_SOURCE_DIRS = source/.                   \
                  source/core                \
                  source/builtin             \
                  source/lexer               \
                  source/executor            \
                  source/utils               
ODIR = ./build

SRCS = $(foreach dir,$(EXE_SOURCE_DIRS),$(wildcard $(dir)/*.c))
OBJS = $(patsubst %.c,$(ODIR)/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)

GREEN = \033[0;32m
BLUE = \033[0;34m
NC = \033[0m

.PHONY: all clean fclean re release

all: $(EXE_NAME)

$(EXE_NAME): $(OBJS) $(LIB_NAME)
	@echo "$(BLUE)Creating executable $(EXE_NAME)...$(NC)"
	@$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIBRARY_DIR) -lslib -lreadline
	@echo "$(GREEN)Executable $(EXE_NAME) created successfully!$(NC)"

$(ODIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(GREEN)Compiled $< to $@$(NC)"

$(LIB_NAME):
	@echo "$(BLUE)Building library $(LIB_NAME)...$(NC)"
	@make -C $(LIBRARY_DIR)
	@echo "$(GREEN)Library $(LIB_NAME) built successfully!$(NC)"

release: CFLAGS += $(RELEASE_CFLAGS)
release: fclean all

clean:
	@echo "$(BLUE)Cleaning up object files...$(NC)"
	@rm -f $(OBJS) $(DEPS)
	@rm -rf $(ODIR)
	@echo "$(GREEN)Cleaned up object files!$(NC)"
	@make -C $(LIBRARY_DIR) clean

fclean: clean
	@echo "$(BLUE)Cleaning up executable and library...$(NC)"
	@rm -f $(EXE_NAME)
	@make -C $(LIBRARY_DIR) fclean
	@echo "$(GREEN)Cleaned up executable and library!$(NC)"

re: fclean all

-include $(DEPS)
