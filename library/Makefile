# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 14:39:40 by plgol.perso       #+#    #+#              #
#    Updated: 2023/12/01 14:39:43 by plgol.perso      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC     =  clang
RM     =  rm -f
CFLAGS =  -Wall                                     \
          -Wextra                                   \
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
          -Wbad-function-cast                       \
          -Wfloat-equal                             \
          -Wformat-type-confusion                   \
          -Wpointer-arith                           \
          -Widiomatic-parentheses                   \
          -Wunreachable-code-aggressive             \
          -fstack-protector-all                     \
          -fPIE                                     \
          -fno-optimize-sibling-calls               \


# CFLAGS =   -Wall                                    \
#            -Wextra                                  \
#            -glldb                                   \

NAME   =    libclib.a
DIRS   =    source/memory                           \
            source/char                             \
            source/string                           \
            source/list                             \
            source/allocator                        \
            source/buffer                           \
            source/queue                            \
            source/stack                            \
            source/scanner                          \
            source/vector                           \
            source/misc                             \
            source/table                            \
            source/bitset                           \
            source/print                            \

SRCS := $(foreach dir,$(DIRS),$(wildcard ./$(dir)/*.c))
OBJS := $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(SHARED_NAME)

re: fclean all

run : $(NAME)
	$(CC) test.c libplib.a $(CFLAGS) -o test
	./test
