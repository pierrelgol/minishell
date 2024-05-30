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
CFLAGS =  -Wall                                     \
          -Wextra                                   \
          -Werror                                   \
          -DDIRECT_IO=1                             \
          -g3                                       \
          -march=native                             \
          -mtune=native                             \
          -fsanitize=address                        \
          -fsanitize=undefined                      \
          -fsanitize=integer                        \
          -fstrict-overflow                         \
          -Walloca                                  \
          -Wformat=2                                \
          -Wformat-security                         \
          -Wnull-dereference                        \
          -Wstack-protector                         \
          -Wvla                                     \
          -Wshorten-64-to-32                        \
          -Warray-bounds                            \
          -Warray-bounds-pointer-arithmetic         \
          -Wimplicit-fallthrough                    \
          -Wloop-analysis                           \
          -Wshift-sign-overflow                     \
          -Wswitch-enum                             \
          -Wtautological-constant-in-range-compare  \
          -Wcomma                                   \
          -Wassign-enum                             \
          -Wfloat-equal                             \
          -Wformat-type-confusion                   \
          -Wpointer-arith                           \
          -Widiomatic-parentheses                   \
          -Wunreachable-code-aggressive             \
          -fstack-protector-all                     \
          -fPIE                                     \
          -fno-optimize-sibling-calls               \

LIBRARY_DIR = ./library
LIB_NAME = $(LIBRARY_DIR)/libclib.a

EXE_HEADER_DIR = ./header
EXE_SOURCE_DIR = source/.                   \
                 source/core                \
                 source/builtin             \
                 source/lexer               \
                 source/executor            \
                 source/utils               
EXE_NAME = minishell

SRCS = $(foreach dir,$(EXE_SOURCE_DIR),$(wildcard $(dir)/*.c))
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(EXE_NAME)

$(EXE_NAME): $(OBJS) $(LIB_NAME)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIBRARY_DIR) -lclib -lreadline

$(LIB_NAME):
	make -C $(LIBRARY_DIR)

clean:
	$(RM) $(OBJS)
	make -C $(LIBRARY_DIR) clean

fclean: clean
	$(RM) $(EXE_NAME)
	make -C $(LIBRARY_DIR) fclean

re: fclean all
	
